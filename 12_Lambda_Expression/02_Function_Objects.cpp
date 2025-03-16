#include <iostream>

struct Comparator
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};


struct Comparator_Desc
{
    bool operator()(int x, int y)
    {
        return x < y;
    }
};

template<typename T, int size, typename Comparator>
void Sort(T (&arr) [size], Comparator comp)
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

struct Printer
{
    void operator()(int x)
    {
        std::cout << x << " ";
    }
};

template<typename T, int size, typename Printer>
void ForEach(T (&arr) [size], Printer printer)
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


int main()
{
    Comparator compare_int;
    Printer printer_int;
    Comparator_Desc compare_int_desc;
    int arr[10] = {9, 8, 7, 33, 1, 44, 55, 2131, 353, 55};
    ForEach(arr, printer_int);
    Sort(arr, compare_int);
    ForEach(arr, printer_int);
    Sort(arr, compare_int_desc);
    ForEach(arr, printer_int);
}