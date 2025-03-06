#include <iostream>
#include "Integer.h"

void Print( Integer obj)
{
    std::cout << obj.GetValue() << std::endl;
}

int main()
{
    Integer a1 { 1 };
    std::cout << "------------" << std::endl;
    Integer a2 { a1 }; //copy constructor called
    std::cout << "------------" << std::endl;
    Integer a3 {static_cast<Integer&&> (a1)}; //move called
    std::cout << "------------" << std::endl;
    //a3-->static cast not readable
    Integer a4 { std::move(a2) };
    std::cout << "------------" << std::endl;
    Integer a5 { 100 };
    Print(a5);
    std::cout << "------------" << std::endl;
    Integer a6 { 500 };
    Print(std::move(a6));
    //std::cout << a6.GetValue() << std::endl;
    std::cout << "------------" << std::endl;
    return 0;
}