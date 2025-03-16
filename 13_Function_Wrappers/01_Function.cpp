#include <iostream>
#include <cstdlib>
#include <functional>

int Square(int x)
{
    return x*x;
}

int* Alloc(size_t bytes)
{
    return (int*)malloc(bytes);
}

struct Max
{
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};


// template <typename Callback>
// int Operation(int x, int y, Callback callback)
// {
//     return callback(x, y);
// }

int Operation(int x, int y, std::function<int(int, int)> callback)
{
    return callback(x, y);
}

int GreaterThan(int x, int y)
{
    return x > y;
}

int main()
{
    std::function<int(int)> f1 = Square;
    std::function<int*(size_t)> f2 = Alloc;
    std::function<bool(int)> f3 = [](int x) { return x%2==0; };

    std::function<int(int, int)> f4;
    if (!f4)
        std::cout << "Target Not Set" << std::endl;
    f4 = Max{};
    if (f4)
        std::cout << "Target Set" << std::endl;

    std::cout << f1(5) << std::endl;
    std::cout << f2(1000) << std::endl;
    std::cout << f3(55) << std::endl;
    std::cout << f4(15,20) << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << Operation(5, 10, GreaterThan) << std::endl;
    std::cout << Operation(5, 10, Max{}) << std::endl;

    return 0;
}