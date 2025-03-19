#include <iostream>
#include <vector>
#include <algorithm>

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> heap_data = {3, 1, 4, 1, 5, 9, 2, 6};

    std::cout << "// make_heap: Converts a range into a max-heap." << std::endl;
    std::cout << "// Permutation 1: Creating a max-heap using default comparison (<)" << std::endl;
    std::make_heap(heap_data.begin(), heap_data.end());
    print(heap_data); // Output will be a max-heap

    std::cout << "// Permutation 2: Creating a min-heap using a custom comparator (std::greater<int>)" << std::endl;
    std::vector<int> min_heap_data = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(min_heap_data.begin(), min_heap_data.end(), std::greater<int>());
    print(min_heap_data); // Output will be a min-heap
    std::cout << std::endl;

    std::cout << "// push_heap: Adds an element to the heap." << std::endl;
    std::cout << "// Permutation 1: Adding an element to the max-heap" << std::endl;
    heap_data.push_back(8);
    std::push_heap(heap_data.begin(), heap_data.end());
    print(heap_data); // The new element is now part of the max-heap

    std::cout << "// Permutation 2: Adding an element to the min-heap" << std::endl;
    min_heap_data.push_back(0);
    std::push_heap(min_heap_data.begin(), min_heap_data.end(), std::greater<int>());
    print(min_heap_data); // The new element is now part of the min-heap
    std::cout << std::endl;

    std::cout << "// pop_heap: Moves the largest element (max-heap) or smallest (min-heap) to the end of the range." << std::endl;
    std::cout << "// Permutation 1: Popping from the max-heap" << std::endl;
    std::pop_heap(heap_data.begin(), heap_data.end());
    print(heap_data); // The largest element (9) is now at the end
    heap_data.pop_back(); // Remove the popped element from the vector
    print(heap_data); // The heap without the largest element

    std::cout << "// Permutation 2: Popping from the min-heap" << std::endl;
    std::pop_heap(min_heap_data.begin(), min_heap_data.end(), std::greater<int>());
    print(min_heap_data); // The smallest element (0) is now at the end
    min_heap_data.pop_back(); // Remove the popped element from the vector
    print(min_heap_data); // The heap without the smallest element
    std::cout << std::endl;

    std::cout << "// sort_heap: Sorts a heap into a sorted range." << std::endl;
    std::cout << "// Permutation 1: Sorting the max-heap" << std::endl;
    std::sort_heap(heap_data.begin(), heap_data.end());
    print(heap_data); // The heap is now a sorted (ascending) range

    std::cout << "// Permutation 2: Sorting the min-heap (will result in descending order)" << std::endl;
    std::sort_heap(min_heap_data.begin(), min_heap_data.end(), std::greater<int>());
    print(min_heap_data); // The min-heap is now a sorted (descending) range
    std::cout << std::endl;

    return 0;
}