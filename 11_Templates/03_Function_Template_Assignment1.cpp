#include <iostream>
#include <utility>

//int Add(int x,int y) ; //Return the sum of two elements
template<typename T>
T add (T a, T b)
{
    return a + b;
}

//int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements
template<typename T>
T ArraySum(const T* pArr, size_t arrSize)
{
    T res = 0;
    for(int i = 0; i < arrSize; i++)
        res += pArr[i];
    return res;
}

//int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array
template<typename T>
T max(const T* pArr, size_t arrSize)
{
    T max = pArr[0];
    for(int i = 1; i < arrSize; i++)
    {
        if(pArr[i] > max)
            max = pArr[i];
    }
    return max;
}

//std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair
template<typename T>
std::pair<T, T> MaxPair(const T* pArr, size_t arrSize)
{
    std::pair<T, T> res;
    res.first = pArr[0]; //small
    res.second = pArr[0]; //large

    for(int i = 1; i < arrSize; i++)
    {
        if(pArr[i] < res.first)
            res.first = pArr[i];
        if (pArr[i] > res.second)
            res.second = pArr[i];
    }
    return res;
}

int main()
{
    int arr[] = {55, 11, 232, 5344, 534312};
    std::cout << add(11, 1) << std::endl;

    std::cout << add<double>(11, 1.1) << std::endl;


    std::cout << ArraySum(arr, 5) << std::endl;
    std::cout << max(arr, 5) << std::endl;

    std::pair<int, int> res = MaxPair(arr, 5);
    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;

    return 0;
}