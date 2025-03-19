#include <iostream>
#include <deque>
#include <algorithm> // For std::fill, std::swap

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::deque<int> deq1;                      // Empty deque
    std::deque<int> deq2 = {10, 20, 30, 40, 50}; // Initialized with an initializer list
    std::deque<int> deq3{1, 2, 3, 4, 5};       // Uniform initialization
    std::deque<int> deq4(5);                   // Deque of size 5, elements default-initialized to 0 (for int)
    std::deque<int> deq5(5, 100);              // Deque of size 5, all elements initialized to 100
    std::deque<int> deq6 = deq2;               // Copy constructor
    std::deque<int> deq7(deq3.begin(), deq3.end()); // Initialize from iterators

    std::cout << "deq2: ";
    for (int val : deq2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "deq4 (size 5, default initialized): ";
    for (int val : deq4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "deq5 (size 5, initialized to 100): ";
    for (int val : deq5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements
    std::cout << "\n// 2. Adding Elements" << std::endl;
    deq1.push_back(1);                      // Adds an element to the end
    deq1.push_back(2);
    deq1.push_front(0);                     // Adds an element to the front
    deq1.emplace_back(3);                   // Constructs an element in-place at the end
    deq1.emplace_front(-1);                // Constructs an element in-place at the front

    std::cout << "deq1 after push_back/front and emplace_back/front: ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq1.insert(deq1.begin() + 2, 10);      // Inserts 10 at the third position
    std::cout << "deq1 after insert(at index 2, 10): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq1.insert(deq1.end(), 2, 20);         // Inserts two 20s at the end
    std::cout << "deq1 after insert(at end, 2 of 20): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "deq2[0]: " << deq2[0] << std::endl; // Using the subscript operator (no bounds checking)
    std::cout << "deq2.at(1): " << deq2.at(1) << std::endl; // Using the at() method (with bounds checking)

    try {
        std::cout << "deq2.at(10): " << deq2.at(10) << std::endl; // This will throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "deq2.front(): " << deq2.front() << std::endl; // Access the first element
    std::cout << "deq2.back(): " << deq2.back() << std::endl;   // Access the last element

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "deq2.size(): " << deq2.size() << std::endl;   // Returns the number of elements
    std::cout << "deq2.empty(): " << deq2.empty() << std::endl; // Returns true if the deque is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    deq1.pop_back();  // Removes the last element
    std::cout << "deq1 after pop_back(): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq1.pop_front(); // Removes the first element
    std::cout << "deq1 after pop_front(): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq1.erase(deq1.begin()); // Removes the first remaining element
    std::cout << "deq1 after erase(begin()): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq1.erase(deq1.begin(), deq1.begin() + 2); // Removes the next two elements
    std::cout << "deq1 after erase(begin(), begin() + 2): ";
    for (int val : deq1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq2.clear(); // Removes all elements from the deque
    std::cout << "deq2 after clear(): size = " << deq2.size() << std::endl;

    // 6. Iterators
    std::cout << "\n// 6. Iterators" << std::endl;
    std::cout << "Iterating through deq3 using iterators: ";
    for (auto it = deq3.begin(); it != deq3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through deq3 using reverse iterators: ";
    for (auto rit = deq3.rbegin(); rit != deq3.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 7. Comparison
    std::cout << "\n// 7. Comparison" << std::endl;
    std::deque<int> deq8 = {1, 2, 3, 4, 5};
    std::deque<int> deq9 = {5, 4, 3, 2, 1};
    std::deque<int> deq10 = {1, 2, 3};

    if (deq3 == deq8) {
        std::cout << "deq3 and deq8 are equal" << std::endl;
    } else {
        std::cout << "deq3 and deq8 are not equal" << std::endl;
    }

    if (deq3 != deq9) {
        std::cout << "deq3 and deq9 are not equal" << std::endl;
    } else {
        std::cout << "deq3 and deq9 are equal" << std::endl;
    }

    if (deq10 < deq3) {
        std::cout << "deq10 is lexicographically less than deq3" << std::endl;
    } else {
        std::cout << "deq10 is not lexicographically less than deq3" << std::endl;
    }

    // 8. Resizing
    std::cout << "\n// 8. Resizing" << std::endl;
    std::cout << "deq9 before resize: size = " << deq9.size() << std::endl;
    deq9.resize(3); // Resizes the deque to contain 3 elements (elements beyond the new size are discarded)
    std::cout << "deq9 after resize(3): size = " << deq9.size() << std::endl;
    std::cout << "deq9 after resize(3): ";
    for (int val : deq9) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    deq9.resize(5, 100); // Resizes to 5 elements, new elements are initialized to 100
    std::cout << "deq9 after resize(5, 100): size = " << deq9.size() << std::endl;
    std::cout << "deq9 after resize(5, 100): ";
    for (int val : deq9) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through deq5 using range-based for loop: ";
    for (int val : deq5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}