#include <iostream>

template<typename T>
using Comparator = bool(*) (T, T);

template<typename T, int size>
void Sort(T (&arr) [size], Comparator<T> comp)
{
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            //if (arr[j] > arr[j+1]) {
            if (comp(arr[j], arr[j+1])) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template<typename T>
using Printer = void(*) (T);

template<typename T, int size>
void ForEach(T (&arr) [size], Printer<T> printer)
{
    for (int i = 0; i < size; i++) {
        printer(arr[i]);
    }
    std::cout << std::endl;
}

bool compare_int(int a, int b)
{
    return a > b;
}

bool compare_int_desc(int a, int b)
{
    return a < b;
}

void printer_int(int a)
{
    std::cout << a << " ";
}

int main()
{
    int arr[10] = {9, 8, 7, 33, 1, 44, 55, 2131, 353, 55};
    ForEach(arr, printer_int);
    Sort(arr, compare_int);
    ForEach(arr, printer_int);
    Sort(arr, compare_int_desc);
    ForEach(arr, printer_int);
}