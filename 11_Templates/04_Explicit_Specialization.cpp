#include <iostream>
#include <cstring>

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

//explicit specialization
template<>
const char* max(const char* a, const char* b)
{
    return (strcmp(a, b) > 0 )? a : b;
}

int main()
{
    std::cout << max(11, 1) << std::endl;
    std::cout << max<double>(2, 22.1) << std::endl;

    const char* a = new char('z');
    const char* b = new char('x');

    std::cout << max(a, b) << std::endl;

    return 0;
}