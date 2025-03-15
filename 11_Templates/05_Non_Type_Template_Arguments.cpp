#include <iostream>

template<int size>
void Print()
{
    std::cout << size << std::endl;
}

template<typename T, int size>
T sum(T(&pArr)[size])
{
    T res = 0;
    for (int i = 0; i < size; i++)
        res += pArr[i];
    return res;
}

int main()
{
    Print<10>();

    int arr[5] = {1, 2, 3, 4, 51};
    std::cout << sum(arr) << std::endl;

    return 0;
}