#include <iostream>
#include <set>
#include <algorithm> // For std::find (though multiset has its own find)

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::multiset<int> multiset1;                      // Empty multiset
    std::multiset<int> multiset2 = {30, 10, 50, 20, 40, 30}; // Initialized with an initializer list (elements will be sorted, duplicates allowed)
    std::multiset<int> multiset3{5, 2, 8, 1, 9, 5};       // Uniform initialization
    std::multiset<int> multiset4(multiset2.begin(), multiset2.end()); // Initialize from iterators
    std::multiset<int> multiset5;
    multiset5.insert({100, 200, 150, 100});           // Inserting multiple elements using an initializer list

    std::cout << "multiset2: ";
    for (int val : multiset2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "multiset5 after inserting multiple elements (including duplicates): ";
    for (int val : multiset5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    multiset1.insert(3);
    multiset1.insert(1);
    multiset1.insert(5);
    multiset1.insert(3); // Duplicate element, will be inserted

    std::cout << "multiset1 after insertions (duplicates allowed): ";
    for (int val : multiset1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it_insert = multiset1.insert(4);
    std::cout << "Inserted element: " << *it_insert << std::endl;

    auto it_insert_duplicate = multiset1.insert(3);
    std::cout << "Inserted duplicate element: " << *it_insert_duplicate << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements in multiset2 (iterating): ";
    for (int val : multiset2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Note: std::multiset does not provide direct access usingor at() for the same reasons as std::set.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "multiset2.size(): " << multiset2.size() << std::endl;   // Returns the number of elements (including duplicates)
    std::cout << "multiset2.empty(): " << multiset2.empty() << std::endl; // Returns true if the multiset is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    multiset3.erase(5); // Erase all elements with value 5
    std::cout << "multiset3 after erasing 5: ";
    for (int val : multiset3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    size_t count = multiset3.erase(10); // Try to erase an element that doesn't exist
    std::cout << "Number of elements erased (value 10): " << count << std::endl;

    auto it_erase = multiset3.find(8);
    if (it_erase != multiset3.end()) {
        multiset3.erase(it_erase); // Erase only the first occurrence of the element using an iterator
        std::cout << "multiset3 after erasing 8 using iterator: ";
        for (int val : multiset3) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    multiset1.clear(); // Removes all elements from the multiset
    std::cout << "multiset1 after clear(): size = " << multiset1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (multiset2.find(30) != multiset2.end()) {
        std::cout << "Element 30 found in multiset2 (first occurrence)" << std::endl;
    } else {
        std::cout << "Element 30 not found in multiset2" << std::endl;
    }

    std::cout << "Count of element 30 in multiset2: " << multiset2.count(30) << std::endl;
    std::cout << "Count of element 10 in multiset2: " << multiset2.count(10) << std::endl;

    auto it_lower = multiset2.lower_bound(25); // Returns an iterator to the first element >= 25
    if (it_lower != multiset2.end()) {
        std::cout << "Lower bound of 25 in multiset2: " << *it_lower << std::endl;
    } else {
        std::cout << "Lower bound of 25 not found (all elements are less)" << std::endl;
    }

    auto it_upper = multiset2.upper_bound(25); // Returns an iterator to the first element > 25
    if (it_upper != multiset2.end()) {
        std::cout << "Upper bound of 25 in multiset2: " << *it_upper << std::endl;
    } else {
        std::cout << "Upper bound of 25 not found (all elements are less or equal)" << std::endl;
    }

    auto range = multiset2.equal_range(30); // Returns a pair of iterators (lower_bound, upper_bound) for elements equal to 30
    std::cout << "Elements equal to 30 in multiset2: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through multiset4 using iterators: ";
    for (auto it = multiset4.begin(); it != multiset4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through multiset4 using reverse iterators: ";
    for (auto rit = multiset4.rbegin(); rit != multiset4.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::multiset<int> multiset6 = {10, 20, 30, 40, 50};
    std::multiset<int> multiset7 = {50, 40, 30, 20, 10};
    std::multiset<int> multiset8 = {10, 20, 30};
    std::multiset<int> multiset9 = {10, 20, 30, 10};

    if (multiset2 == multiset6) {
        std::cout << "multiset2 and multiset6 are equal" << std::endl;
    } else {
        std::cout << "multiset2 and multiset6 are not equal" << std::endl;
    }

    if (multiset2 != multiset7) {
        std::cout << "multiset2 and multiset7 are not equal (order matters for equality)" << std::endl;
    } else {
        std::cout << "multiset2 and multiset7 are equal" << std::endl;
    }

    if (multiset8 < multiset2) {
        std::cout << "multiset8 is lexicographically less than multiset2" << std::endl;
    } else {
        std::cout << "multiset8 is not lexicographically less than multiset2" << std::endl;
    }

    if (multiset8 < multiset9) {
        std::cout << "multiset8 is lexicographically less than multiset9" << std::endl;
    } else {
        std::cout << "multiset8 is not lexicographically less than multiset9" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through multiset3 using range-based for loop: ";
    for (int val : multiset3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}