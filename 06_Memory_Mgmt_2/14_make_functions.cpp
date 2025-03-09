#include <iostream>
#include <memory>

int main()
{
    auto p = std::make_unique<int>(10);
    std::cout << *p << std::endl;

    auto p2 = std::make_unique<int[]>(5);
    p2[1] = 2323;
    std::cout << p2[1] << std::endl;

    auto p3 = std::make_shared<int>(20);
    std::cout << *p3 << std::endl;

    //NOT WORK
    // auto p4 = std::make_shared<int[]>(5);

    return 0;
}
