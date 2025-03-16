#include <iostream>

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
    for (int i = 0; i < size - 1; ++i) {
        operation(arr[i]);
    }
}

class Product {
    std::string name;
    float price;
public:
    Product(const std::string &n, float p) :name(n), price(p) {

    }
    void AssignFinalPrice() {
        float taxes[]{ 12, 5, 5 };
        float basePrice{ price };
        //Capture this
        ForEach(taxes, [basePrice, this](float tax) {
            float taxedPrice = basePrice * tax / 100;
            price += taxedPrice;
        });
    }
    float GetPrice()const {
        return price;
    }
};

int main()
{
    int arr[]{ 1,6,8,4,0 };

    ForEach(arr, [](auto x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;

    int offset = 5;
    ForEach(arr, [offset](auto &x) {
        x += offset;
    });
    ForEach(arr, [](auto x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;

    ForEach(arr, [offset](auto &x)mutable {
    	x += offset;
    	++offset;
    });
    std::cout << "offset: " << offset << std::endl;

    int sum{};
    ForEach(arr, [&, offset](auto &x) {
        sum += x;
    });
    std::cout << "Sum:" << sum << std::endl;

    ForEach(arr, [](auto x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;

    Product p{ "Watch", 500 };
    p.AssignFinalPrice();
    std::cout << p.GetPrice() << std::endl;*

    return 0;
}

