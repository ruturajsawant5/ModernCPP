#include <iostream>
#include <vector>
#include <algorithm> // For std::fill, std::swap, std::sort

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::vector<int> vec1;                      // Empty vector
    std::vector<int> vec2 = {10, 20, 30, 40, 50}; // Initialized with an initializer list
    std::vector<int> vec3{1, 2, 3, 4, 5};       // Uniform initialization
    std::vector<int> vec4(5);                   // Vector of size 5, elements default-initialized to 0 (for int)
    std::vector<int> vec5(5, 100);              // Vector of size 5, all elements initialized to 100
    std::vector<int> vec6 = vec2;               // Copy constructor
    std::vector<int> vec7(vec3.begin(), vec3.end()); // Initialize from iterators

    std::cout << "vec2: ";
    for (int val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "vec4 (size 5, default initialized): ";
    for (int val : vec4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "vec5 (size 5, initialized to 100): ";
    for (int val : vec5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements
    std::cout << "\n// 2. Adding Elements" << std::endl;
    vec1.push_back(1);                      // Adds an element to the end
    vec1.push_back(2);
    vec1.emplace_back(3);                   // Constructs an element in-place at the end (often more efficient)

    std::cout << "vec1 after push_back/emplace_back: ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec1.insert(vec1.begin() + 1, 10);      // Inserts 10 at the second position
    std::cout << "vec1 after insert(at index 1, 10): ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec1.insert(vec1.end(), 2, 20);         // Inserts two 20s at the end
    std::cout << "vec1 after insert(at end, 2 of 20): ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "vec2[0]: " << vec2[0] << std::endl; // Using the subscript operator (no bounds checking)
    std::cout << "vec2.at(1): " << vec2.at(1) << std::endl; // Using the at() method (with bounds checking)

    try {
        std::cout << "vec2.at(10): " << vec2.at(10) << std::endl; // This will throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "vec2.front(): " << vec2.front() << std::endl; // Access the first element
    std::cout << "vec2.back(): " << vec2.back() << std::endl;   // Access the last element
    std::cout << "vec2.data(): " << vec2.data() << std::endl;   // Returns a pointer to the underlying array

    // 4. Size and Capacity
    std::cout << "\n// 4. Size and Capacity" << std::endl;
    std::cout << "vec2.size(): " << vec2.size() << std::endl;     // Returns the number of elements
    std::cout << "vec2.capacity(): " << vec2.capacity() << std::endl; // Returns the number of elements the vector has allocated space for
    std::cout << "vec2.empty(): " << vec2.empty() << std::endl;   // Returns true if the vector is empty (size is 0)

    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << std::endl;

    vec1.reserve(10); // Requests that the vector's capacity be at least enough for 10 elements
    std::cout << "vec1.capacity() after reserve(10): " << vec1.capacity() << std::endl;

    vec1.shrink_to_fit(); // Requests to reduce capacity to fit the current size (may not always happen)
    std::cout << "vec1.capacity() after shrink_to_fit(): " << vec1.capacity() << std::endl;

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    vec1.pop_back(); // Removes the last element
    std::cout << "vec1 after pop_back(): ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec1.erase(vec1.begin()); // Removes the first element
    std::cout << "vec1 after erase(begin()): ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec1.erase(vec1.begin(), vec1.begin() + 2); // Removes the first two elements
    std::cout << "vec1 after erase(begin(), begin() + 2): ";
    for (int val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec2.clear(); // Removes all elements from the vector (size becomes 0, but capacity may remain)
    std::cout << "vec2 after clear(): size = " << vec2.size() << ", capacity = " << vec2.capacity() << std::endl;

    // 6. Iterators
    std::cout << "\n// 6. Iterators" << std::endl;
    std::cout << "Iterating through vec3 using iterators: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through vec3 using reverse iterators: ";
    for (auto rit = vec3.rbegin(); rit != vec3.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 7. Comparison
    std::cout << "\n// 7. Comparison" << std::endl;
    std::vector<int> vec8 = {1, 2, 3, 4, 5};
    std::vector<int> vec9 = {5, 4, 3, 2, 1};
    std::vector<int> vec10 = {1, 2, 3};

    if (vec3 == vec8) {
        std::cout << "vec3 and vec8 are equal" << std::endl;
    } else {
        std::cout << "vec3 and vec8 are not equal" << std::endl;
    }

    if (vec3 != vec9) {
        std::cout << "vec3 and vec9 are not equal" << std::endl;
    } else {
        std::cout << "vec3 and vec9 are equal" << std::endl;
    }

    if (vec10 < vec3) {
        std::cout << "vec10 is lexicographically less than vec3" << std::endl;
    } else {
        std::cout << "vec10 is not lexicographically less than vec3" << std::endl;
    }

    // 8. Resizing
    std::cout << "\n// 8. Resizing" << std::endl;
    std::cout << "vec9 before resize: size = " << vec9.size() << ", capacity = " << vec9.capacity() << std::endl;
    vec9.resize(3); // Resizes the vector to contain 3 elements (elements beyond the new size are discarded)
    std::cout << "vec9 after resize(3): size = " << vec9.size() << ", capacity = " << vec9.capacity() << std::endl;
    std::cout << "vec9 after resize(3): ";
    for (int val : vec9) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    vec9.resize(5, 100); // Resizes to 5 elements, new elements are initialized to 100
    std::cout << "vec9 after resize(5, 100): size = " << vec9.size() << ", capacity = " << vec9.capacity() << std::endl;
    std::cout << "vec9 after resize(5, 100): ";
    for (int val : vec9) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through vec5 using range-based for loop: ";
    for (int val : vec5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}