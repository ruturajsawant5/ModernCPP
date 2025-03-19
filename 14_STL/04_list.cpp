#include <iostream>
#include <list>
#include <algorithm> // For std::sort, std::remove, std::remove_if

// Predicate function for remove_if example
bool is_even(int value) {
    return (value % 2 == 0);
}

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::list<int> list1;                      // Empty list
    std::list<int> list2 = {10, 20, 30, 40, 50}; // Initialized with an initializer list
    std::list<int> list3{1, 2, 3, 4, 5};       // Uniform initialization
    std::list<int> list4(5);                   // List of size 5, elements default-initialized to 0 (for int)
    std::list<int> list5(5, 100);              // List of size 5, all elements initialized to 100
    std::list<int> list6 = list2;             // Copy constructor
    std::list<int> list7(list3.begin(), list3.end()); // Initialize from iterators

    std::cout << "list2: ";
    for (int val : list2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "list4 (size 5, default initialized): ";
    for (int val : list4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "list5 (size 5, initialized to 100): ";
    for (int val : list5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements
    std::cout << "\n// 2. Adding Elements" << std::endl;
    list1.push_back(1);                      // Adds an element to the end
    list1.push_back(2);
    list1.push_front(0);                     // Adds an element to the front
    list1.emplace_back(3);                   // Constructs an element in-place at the end
    list1.emplace_front(-1);                // Constructs an element in-place at the front

    std::cout << "list1 after push_back/front and emplace_back/front: ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it_insert = std::next(list1.begin(), 2); // Get an iterator to the third position
    list1.insert(it_insert, 10);              // Inserts 10 before the element at the iterator
    std::cout << "list1 after insert(before third element, 10): ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list1.insert(list1.end(), 2, 20);         // Inserts two 20s at the end
    std::cout << "list1 after insert(at end, 2 of 20): ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "list2.front(): " << list2.front() << std::endl; // Access the first element
    std::cout << "list2.back(): " << list2.back() << std::endl;   // Access the last element
    // Note: std::list does not provide direct access usingor at() because it's not a contiguous data structure.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "list2.size(): " << list2.size() << std::endl;   // Returns the number of elements
    std::cout << "list2.empty(): " << list2.empty() << std::endl; // Returns true if the list is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    list1.pop_back();  // Removes the last element
    std::cout << "list1 after pop_back(): ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list1.pop_front(); // Removes the first element
    std::cout << "list1 after pop_front(): ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it_erase = std::next(list1.begin()); // Get an iterator to the second element
    list1.erase(it_erase); // Removes the element at the iterator
    std::cout << "list1 after erase(second element): ";
    for (int val : list1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list3.remove(3); // Removes all elements with the value 3
    std::cout << "list3 after remove(3): ";
    for (int val : list3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list5.remove_if(is_even); // Removes all even numbers using a predicate function
    std::cout << "list5 after remove_if(is_even): ";
    for (int val : list5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list6.clear(); // Removes all elements from the list
    std::cout << "list6 after clear(): size = " << list6.size() << std::endl;

    // 6. Iterators
    std::cout << "\n// 6. Iterators" << std::endl;
    std::cout << "Iterating through list7 using iterators: ";
    for (auto it = list7.begin(); it != list7.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through list7 using reverse iterators: ";
    for (auto rit = list7.rbegin(); rit != list7.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 7. Special List Operations
    std::cout << "\n// 7. Special List Operations" << std::endl;
    std::list<int> list_splice1 = {100, 200, 300};
    std::list<int> list_splice2 = {1, 2, 3, 4, 5};
    auto it_splice = std::next(list_splice2.begin(), 2); // Iterator to the third element of list_splice2
    list_splice2.splice(it_splice, list_splice1); // Move all elements from list_splice1 before it_splice
    std::cout << "list_splice2 after splice(before third element, list_splice1): ";
    for (int val : list_splice2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "list_splice1 after splice: size = " << list_splice1.size() << std::endl;

    std::list<int> list_merge1 = {1, 3, 5};
    std::list<int> list_merge2 = {2, 4, 6};
    list_merge1.merge(list_merge2); // Merge sorted list_merge2 into sorted list_merge1
    std::cout << "list_merge1 after merge(list_merge2): ";
    for (int val : list_merge1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "list_merge2 after merge: size = " << list_merge2.size() << std::endl;

    std::list<int> list_sort = {5, 2, 8, 1, 9, 3};
    list_sort.sort(); // Sort the list
    std::cout << "list_sort after sort(): ";
    for (int val : list_sort) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::list<int> list_reverse = {1, 2, 3, 4, 5};
    list_reverse.reverse(); // Reverse the order of elements
    std::cout << "list_reverse after reverse(): ";
    for (int val : list_reverse) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::list<int> list_unique = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    list_unique.unique(); // Remove consecutive duplicate elements
    std::cout << "list_unique after unique(): ";
    for (int val : list_unique) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::list<int> list8 = {1, 2, 3, 4, 5};
    std::list<int> list9 = {5, 4, 3, 2, 1};
    std::list<int> list10 = {1, 2, 3};

    if (list3 == list8) {
        std::cout << "list3 and list8 are equal" << std::endl;
    } else {
        std::cout << "list3 and list8 are not equal" << std::endl;
    }

    if (list3 != list9) {
        std::cout << "list3 and list9 are not equal" << std::endl;
    } else {
        std::cout << "list3 and list9 are equal" << std::endl;
    }

    if (list10 < list3) {
        std::cout << "list10 is lexicographically less than list3" << std::endl;
    } else {
        std::cout << "list10 is not lexicographically less than list3" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through list7 using range-based for loop: ";
    for (int val : list7) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}