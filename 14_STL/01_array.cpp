#include <iostream>
#include <array>
#include <algorithm> // For std::fill and std::swap

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::array<int, 5> arr1;               // Uninitialized (elements have indeterminate values)
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5}; // Initialized with an initializer list
    std::array<int, 5> arr3{10, 20, 30, 40, 50}; // Uniform initialization
    std::array<int, 5> arr4;
    arr4.fill(0);                           // Initialize all elements to 0

    std::cout << "arr2: ";
    for (int val : arr2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "arr4 after fill(0): ";
    for (int val : arr4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Accessing Elements
    std::cout << "\n// 2. Accessing Elements" << std::endl;
    std::cout << "arr2[0]: " << arr2[0] << std::endl; // Using the subscript operator (no bounds checking)
    std::cout << "arr2.at(1): " << arr2.at(1) << std::endl; // Using the at() method (with bounds checking)

    try {
        std::cout << "arr2.at(10): " << arr2.at(10) << std::endl; // This will throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "arr2.front(): " << arr2.front() << std::endl; // Access the first element
    std::cout << "arr2.back(): " << arr2.back() << std::endl;   // Access the last element
    std::cout << "arr2.data(): " << arr2.data() << std::endl;   // Returns a pointer to the underlying array

    // 3. Size and Capacity
    std::cout << "\n// 3. Size and Capacity" << std::endl;
    std::cout << "arr2.size(): " << arr2.size() << std::endl;   // Returns the number of elements
    std::cout << "arr2.max_size(): " << arr2.max_size() << std::endl; // Same as size for std::array

    // 4. Iterators
    std::cout << "\n// 4. Iterators" << std::endl;
    std::cout << "Iterating through arr3 using iterators: ";
    for (auto it = arr3.begin(); it != arr3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through arr3 using reverse iterators: ";
    for (auto rit = arr3.rbegin(); rit != arr3.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 5. Comparison
    std::cout << "\n// 5. Comparison" << std::endl;
    std::array<int, 5> arr5 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr6 = {5, 4, 3, 2, 1};

    if (arr2 == arr5) {
        std::cout << "arr2 and arr5 are equal" << std::endl;
    } else {
        std::cout << "arr2 and arr5 are not equal" << std::endl;
    }

    if (arr2 != arr6) {
        std::cout << "arr2 and arr6 are not equal" << std::endl;
    } else {
        std::cout << "arr2 and arr6 are equal" << std::endl;
    }

    if (arr2 < arr6) {
        std::cout << "arr2 is lexicographically less than arr6" << std::endl;
    } else {
        std::cout << "arr2 is not lexicographically less than arr6" << std::endl;
    }

    // 6. fill()
    std::cout << "\n// 6. fill()" << std::endl;
    arr1.fill(100);
    std::cout << "arr1 after fill(100): ";
    for (int val : arr1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 7. swap()
    std::cout << "\n// 7. swap()" << std::endl;
    std::cout << "Before swap: arr2 = ";
    for (int val : arr2) {
        std::cout << val << " ";
    }
    std::cout << ", arr3 = ";
    for (int val : arr3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    arr2.swap(arr3);

    std::cout << "After swap: arr2 = ";
    for (int val : arr2) {
        std::cout << val << " ";
    }
    std::cout << ", arr3 = ";
    for (int val : arr3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 8. Range-based for loop
    std::cout << "\n// 8. Range-based for loop" << std::endl;
    std::cout << "Iterating through arr4 using range-based for loop: ";
    for (int val : arr4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}