#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> p{new int[]{1,2,3,4,5}};
    p.get()[0] = 100;
    p = nullptr; //will call delete instead of delete[]

    std::unique_ptr<int[]> p2{new int[]{1,2,3,4,5}};
    p2[0] = 100;
    p2 = nullptr; //will call delete[]

    //C++17 added this
    std::shared_ptr<int[]>p3 {new int[]{1,2,3,4,5}};
    p3[4] = 100;
    p3 = nullptr;

    return 0;
}
