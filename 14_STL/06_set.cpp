#include <iostream>
#include <set>
#include <algorithm> // For std::find (though set has its own find)

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::set<int> set1;                      // Empty set
    std::set<int> set2 = {30, 10, 50, 20, 40}; // Initialized with an initializer list (elements will be sorted)
    std::set<int> set3{5, 2, 8, 1, 9};       // Uniform initialization
    std::set<int> set4(set2.begin(), set2.end()); // Initialize from iterators
    std::set<int> set5;
    set5.insert({100, 200, 150});           // Inserting multiple elements using an initializer list

    std::cout << "set2: ";
    for (int val : set2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "set5 after inserting multiple elements: ";
    for (int val : set5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    set1.insert(3);
    set1.insert(1);
    set1.insert(5);
    set1.insert(3); // Duplicate element, will not be inserted

    std::cout << "set1 after insertions: ";
    for (int val : set1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto result = set1.insert(4);
    if (result.second) {
        std::cout << "Inserted element: " << *result.first << std::endl;
    } else {
        std::cout << "Element not inserted (already exists): " << *result.first << std::endl;
    }

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements in set2 (iterating): ";
    for (int val : set2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Note: std::set does not provide direct access usingor at() because it's an ordered collection based on keys (values in this case).

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "set2.size(): " << set2.size() << std::endl;   // Returns the number of elements
    std::cout << "set2.empty(): " << set2.empty() << std::endl; // Returns true if the set is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    set3.erase(2); // Erase element with value 2
    std::cout << "set3 after erasing 2: ";
    for (int val : set3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    size_t count = set3.erase(10); // Try to erase an element that doesn't exist
    std::cout << "Number of elements erased (value 10): " << count << std::endl;

    auto it_erase = set3.find(8);
    if (it_erase != set3.end()) {
        set3.erase(it_erase); // Erase element using an iterator
        std::cout << "set3 after erasing 8 using iterator: ";
        for (int val : set3) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    set1.clear(); // Removes all elements from the set
    std::cout << "set1 after clear(): size = " << set1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (set2.find(30) != set2.end()) {
        std::cout << "Element 30 found in set2" << std::endl;
    } else {
        std::cout << "Element 30 not found in set2" << std::endl;
    }

    if (set2.count(10) > 0) {
        std::cout << "Element 10 is present in set2 (count: " << set2.count(10) << ")" << std::endl;
    } else {
        std::cout << "Element 10 is not present in set2" << std::endl;
    }

    auto it_lower = set2.lower_bound(25); // Returns an iterator to the first element >= 25
    if (it_lower != set2.end()) {
        std::cout << "Lower bound of 25 in set2: " << *it_lower << std::endl;
    } else {
        std::cout << "Lower bound of 25 not found (all elements are less)" << std::endl;
    }

    auto it_upper = set2.upper_bound(25); // Returns an iterator to the first element > 25
    if (it_upper != set2.end()) {
        std::cout << "Upper bound of 25 in set2: " << *it_upper << std::endl;
    } else {
        std::cout << "Upper bound of 25 not found (all elements are less or equal)" << std::endl;
    }

    auto range = set2.equal_range(30); // Returns a pair of iterators (lower_bound, upper_bound) for elements equal to 30
    std::cout << "Elements equal to 30 in set2: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through set4 using iterators: ";
    for (auto it = set4.begin(); it != set4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through set4 using reverse iterators: ";
    for (auto rit = set4.rbegin(); rit != set4.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::set<int> set6 = {10, 20, 30, 40, 50};
    std::set<int> set7 = {50, 40, 30, 20, 10};
    std::set<int> set8 = {10, 20, 30};

    if (set2 == set6) {
        std::cout << "set2 and set6 are equal" << std::endl;
    } else {
        std::cout << "set2 and set6 are not equal" << std::endl;
    }

    if (set2 != set7) {
        std::cout << "set2 and set7 are not equal (order doesn't matter for equality)" << std::endl;
    } else {
        std::cout << "set2 and set7 are equal" << std::endl;
    }

    if (set8 < set2) {
        std::cout << "set8 is lexicographically less than set2" << std::endl;
    } else {
        std::cout << "set8 is not lexicographically less than set2" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through set3 using range-based for loop: ";
    for (int val : set3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}