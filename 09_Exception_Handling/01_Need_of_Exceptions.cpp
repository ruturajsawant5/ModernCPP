#include <iostream>

int ProcessRecords(int count)
{
    int* arr = (int*)malloc(count * sizeof(int));
    if(arr == nullptr)
    {
        std::cout  << "malloc() failed" << std::endl;
        return -1; //error code denote which error happened
    }

    for(int i = 0; i < count; i++)
        arr[i] = i;

    std::cout  << "ProcessRecords()" << std::endl;
    return 0;
}

int main()
{
    //caller is choosing to ignore the return value
    //callee cant enforce handling of error in caller
    //un-handled errors can cause program crash
    ProcessRecords(std::numeric_limits<int>::max());
    return 0;
}