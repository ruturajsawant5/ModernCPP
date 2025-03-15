#include <iostream>

int max(int a, int b)
{
    return a > b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}
// ...
int main()
{
    std::cout << max(11, 1) << std::endl;
    std::cout << max(2.5, 22.1) << std::endl;
    return 0;
}