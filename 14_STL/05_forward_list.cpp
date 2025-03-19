#include <iostream>
#include <forward_list>
#include <algorithm> // For std::sort, std::remove, std::remove_if

// Predicate function for remove_if example
bool is_even_fl(int value) {
    return (value % 2 == 0);
}

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::forward_list<int> flist1;                      // Empty forward_list
    std::forward_list<int> flist2 = {10, 20, 30, 40, 50}; // Initialized with an initializer list
    std::forward_list<int> flist3{1, 2, 3, 4, 5};       // Uniform initialization
    std::forward_list<int> flist4(5);                   // forward_list of size 5, elements default-initialized to 0 (for int)
    std::forward_list<int> flist5(5, 100);              // forward_list of size 5, all elements initialized to 100
    std::forward_list<int> flist6 = flist2;             // Copy constructor
    std::forward_list<int> flist7(flist3.begin(), flist3.end()); // Initialize from iterators

    std::cout << "flist2: ";
    for (int val : flist2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "flist4 (size 5, default initialized): ";
    for (int val : flist4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "flist5 (size 5, initialized to 100): ";
    for (int val : flist5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements
    std::cout << "\n// 2. Adding Elements" << std::endl;
    flist1.push_front(1);                   // Adds an element to the front
    flist1.push_front(0);
    flist1.emplace_front(-1);                // Constructs an element in-place at the front

    std::cout << "flist1 after push_front and emplace_front: ";
    for (int val : flist1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it_insert = flist1.begin(); // Insert after the first element
    flist1.insert_after(it_insert, 10);
    std::cout << "flist1 after insert_after(first element, 10): ";
    for (int val : flist1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    it_insert = flist1.before_begin(); // Insert at the beginning (effectively push_front)
    flist1.insert_after(it_insert, -2);
    std::cout << "flist1 after insert_after(before_begin(), -2): ";
    for (int val : flist1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "flist2.front(): " << flist2.front() << std::endl; // Access the first element
    // Note: std::forward_list only provides direct access to the first element. There is no direct way to access the last element or elements at arbitrary positions efficiently.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "flist2.empty(): " << flist2.empty() << std::endl; // Returns true if the forward_list is empty (size is 0)
    // Note: std::forward_list does not have a size() method for efficiency reasons. Calculating the size would require traversing the entire list.

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    flist1.pop_front(); // Removes the first element
    std::cout << "flist1 after pop_front(): ";
    for (int val : flist1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it_erase = flist1.begin(); // Erase after the first element
    flist1.erase_after(it_erase);
    std::cout << "flist1 after erase_after(first element): ";
    for (int val : flist1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    flist3.remove(3); // Removes all elements with the value 3
    std::cout << "flist3 after remove(3): ";
    for (int val : flist3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    flist5.remove_if(is_even_fl); // Removes all even numbers using a predicate function
    std::cout << "flist5 after remove_if(is_even_fl): ";
    for (int val : flist5) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    flist6.clear(); // Removes all elements from the forward_list
    std::cout << "flist6 after clear(): empty = " << flist6.empty() << std::endl;

    // 6. Iterators
    std::cout << "\n// 6. Iterators" << std::endl;
    std::cout << "Iterating through flist7 using iterators: ";
    for (auto it = flist7.begin(); it != flist7.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Note: std::forward_list only provides forward iterators. There are no reverse iterators.

    // 7. Special Forward List Operations
    std::cout << "\n// 7. Special Forward List Operations" << std::endl;
    std::forward_list<int> flist_splice1 = {100, 200, 300};
    std::forward_list<int> flist_splice2 = {1, 2, 3, 4, 5};
    auto it_splice = flist_splice2.begin(); // Iterator to the first element of flist_splice2
    flist_splice2.splice_after(flist_splice2.before_begin(), flist_splice1); // Move all elements from flist_splice1 to the beginning of flist_splice2
    std::cout << "flist_splice2 after splice_after(before_begin(), flist_splice1): ";
    for (int val : flist_splice2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "flist_splice1 after splice_after: empty = " << flist_splice1.empty() << std::endl;

    std::forward_list<int> flist_merge1 = {1, 3, 5};
    std::forward_list<int> flist_merge2 = {2, 4, 6};
    flist_merge1.merge(flist_merge2); // Merge sorted flist_merge2 into sorted flist_merge1
    std::cout << "flist_merge1 after merge(flist_merge2): ";
    for (int val : flist_merge1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "flist_merge2 after merge: empty = " << flist_merge2.empty() << std::endl;

    std::forward_list<int> flist_sort = {5, 2, 8, 1, 9, 3};
    flist_sort.sort(); // Sort the forward_list
    std::cout << "flist_sort after sort(): ";
    for (int val : flist_sort) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::forward_list<int> flist_reverse = {1, 2, 3, 4, 5};
    flist_reverse.reverse(); // Reverse the order of elements
    std::cout << "flist_reverse after reverse(): ";
    for (int val : flist_reverse) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::forward_list<int> flist_unique = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    flist_unique.unique(); // Remove consecutive duplicate elements
    std::cout << "flist_unique after unique(): ";
    for (int val : flist_unique) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::forward_list<int> flist8 = {1, 2, 3, 4, 5};
    std::forward_list<int> flist9 = {5, 4, 3, 2, 1};
    std::forward_list<int> flist10 = {1, 2, 3};

    if (flist3 == flist8) {
        std::cout << "flist3 and flist8 are equal" << std::endl;
    } else {
        std::cout << "flist3 and flist8 are not equal" << std::endl;
    }

    if (flist3 != flist9) {
        std::cout << "flist3 and flist9 are not equal" << std::endl;
    } else {
        std::cout << "flist3 and flist9 are equal" << std::endl;
    }

    if (flist10 < flist3) {
        std::cout << "flist10 is lexicographically less than flist3" << std::endl;
    } else {
        std::cout << "flist10 is not lexicographically less than flist3" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through flist7 using range-based for loop: ";
    for (int val : flist7) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}