#include <iostream>

int main()
{
    int x = 10;
    std::cout << x << "\n";

    //Always try to initialize pointers to nullptr
    int *ptr = nullptr;
    std::cout << *ptr << "\n";
    *ptr = 5;

    return 0; 
}
