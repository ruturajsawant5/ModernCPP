#include <iostream>
#include <memory>
#include <cstdlib>

struct Free
{
    void operator()(int* ptr)
    {
        free(ptr);
        std::cout << "Free::Called" << std::endl;
    }
};

void MallocFree(int * ptr)
{
    free(ptr);
    std::cout << "MallocFree::Called" << std::endl;
}

int main()
{
    //Unique Ptr
    //1. Function Object
    std::unique_ptr<int, Free> p1((int*)malloc(4), Free{});
    *p1 = 100;
    std::cout << *p1 << std::endl;

    //2. Function Pointer
    std::unique_ptr<int , void(*)(int*)> p2((int*)malloc(4), MallocFree);
    *p2 = 200;
    std::cout << *p2 << std::endl;

    //Shared Ptr
    //1. Function Object
    std::shared_ptr<int> p3((int*)malloc(4), Free{});
    *p3 = 300;
    std::cout << *p3 << std::endl;

    //2. Function Pointer
    std::shared_ptr<int> p4((int*)malloc(4), MallocFree);
    *p4 = 400;
    std::cout << *p4 << std::endl;

    return 0;
}
