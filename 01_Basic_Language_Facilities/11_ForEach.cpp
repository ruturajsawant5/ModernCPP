#include <iostream>
int main()
{
    int arr[] = { 1,2,3,4,5 };
    for (int i = 0; i < 5; i++) 
    {
        std::cout << arr[i] << " ";
	}
    for (const auto & x : arr)
    {
        std::cout << x << " ";
    }
    for (auto x : { 1,2,3,4 })
    {
        std::cout << x;
    }
    return 0;
}
