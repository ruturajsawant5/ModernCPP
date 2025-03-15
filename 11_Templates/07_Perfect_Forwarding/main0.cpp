#include <iostream>
#include "Integer.h"
int main()
{
    Integer I1{10};
    std::cout << "--------------------------" << std::endl;
    Integer I2{I1};
    std::cout << "--------------------------" << std::endl;
    I2 = I1;
    std::cout << "--------------------------" << std::endl;
    I2 = std::move(I1);
    std::cout << "--------------------------" << std::endl;
    return 0;
}