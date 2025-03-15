#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b)
{
    if(std::is_floating_point<T>::value == false)
    {
        std::cerr << "Divide by not float" << std::endl;
        return 0;
    }
    return a / b;
}

int main()
{
    std::cout << Divide(100, 5) << std::endl;
}