#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b)
{
    static_assert(std::is_floating_point<T>::value, "Should never be a floating point type");
    return a / b;
}

int main()
{
    std::cout << Divide(100.0, 5.0) << std::endl;
}