#include <iostream>

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout << max(11, 1) << std::endl;
    std::cout << max(2.5, 22.1) << std::endl;
    return 0;
}