#include <iostream>

int ProcessRecords(int count)
{
    int* arr = nullptr; //(int*)malloc(count * sizeof(int));
    if(arr == nullptr)
    {
        throw std::runtime_error("Memory allocation failed");
        //return -1; //Unreachable Code
    }

    for(int i = 0; i < count; i++)
        arr[i] = i;
    std::cout  << "ProcessRecords()" << std::endl;
    return 0;
}

int main()
{
    try
    {
        ProcessRecords(std::numeric_limits<int>::max());
    }
    catch (std::runtime_error &e) {
        //catch by ref to avoid copy
        std::cout << e.what() << std::endl;
    }
    return 0;
}