#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::unordered_multiset<std::string> umset1;                      // Empty unordered_multiset
    std::unordered_multiset<std::string> umset2 = {"apple", "banana", "cherry", "apple"}; // Initialized with an initializer list (duplicates allowed)
    std::unordered_multiset<std::string> umset3{"dog", "cat", "elephant", "dog"};       // Uniform initialization
    std::unordered_multiset<std::string> umset4(umset2.begin(), umset2.end()); // Initialize from iterators
    std::unordered_multiset<std::string> umset5;
    umset5.insert({"grape", "kiwi", "mango", "grape"}); // Inserting multiple elements (including duplicates)

    std::cout << "umset2: ";
    for (const std::string& str : umset2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "umset5 after inserting multiple elements (including duplicates): ";
    for (const std::string& str : umset5) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    umset1.insert("one");
    umset1.insert("two");
    umset1.insert("three");
    umset1.insert("one"); // Duplicate element, will be inserted

    std::cout << "umset1 after insertions (duplicates allowed): ";
    for (const std::string& str : umset1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    auto it_insert = umset1.insert("four");
    std::cout << "Inserted element: " << *it_insert << std::endl;

    auto it_insert_duplicate = umset1.insert("one");
    std::cout << "Inserted duplicate element: " << *it_insert_duplicate << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements in umset2 (iterating): ";
    for (const std::string& str : umset2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    // Note: std::unordered_multiset does not provide direct access usingor at() because the order of elements is not guaranteed.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "umset2.size(): " << umset2.size() << std::endl;   // Returns the number of elements (including duplicates)
    std::cout << "umset2.empty(): " << umset2.empty() << std::endl; // Returns true if the unordered_multiset is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    umset3.erase("dog"); // Erase all elements with value "dog"
    std::cout << "umset3 after erasing \"dog\": ";
    for (const std::string& str : umset3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    size_t count = umset3.erase("lion"); // Try to erase an element that doesn't exist
    std::cout << "Number of elements erased (value \"lion\"): " << count << std::endl;

    auto it_erase = umset3.find("cat");
    if (it_erase != umset3.end()) {
        umset3.erase(it_erase); // Erase only the first occurrence of the element using an iterator
        std::cout << "umset3 after erasing \"cat\" using iterator: ";
        for (const std::string& str : umset3) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    umset1.clear(); // Removes all elements from the unordered_multiset
    std::cout << "umset1 after clear(): size = " << umset1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (umset2.find("banana") != umset2.end()) {
        std::cout << "Element \"banana\" found in umset2 (first occurrence)" << std::endl;
    } else {
        std::cout << "Element \"banana\" not found in umset2" << std::endl;
    }

    std::cout << "Count of element \"apple\" in umset2: " << umset2.count("apple") << std::endl;
    std::cout << "Count of element \"cherry\" in umset2: " << umset2.count("cherry") << std::endl;

    // Note: unordered_multiset does not provide lower_bound, upper_bound, or equal_range as it's not ordered.

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through umset4 using iterators: ";
    for (auto it = umset4.begin(); it != umset4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Note: unordered_multiset iterators are forward iterators. There are no reverse iterators.

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::unordered_multiset<std::string> umset6 = {"apple", "banana", "cherry", "apple"};
    std::unordered_multiset<std::string> umset7 = {"banana", "apple", "cherry", "apple"};
    std::unordered_multiset<std::string> umset8 = {"apple", "banana"};
    std::unordered_multiset<std::string> umset9 = {"banana", "apple", "apple"};

    if (umset2 == umset6) {
        std::cout << "umset2 and umset6 are equal" << std::endl;
    } else {
        std::cout << "umset2 and umset6 are not equal" << std::endl;
    }

    if (umset2 == umset7) {
        std::cout << "umset2 and umset7 are equal (order doesn't matter, but counts do)" << std::endl;
    } else {
        std::cout << "umset2 and umset7 are not equal" << std::endl;
    }

    // Comparison operators like <, >, <=, >= are generally not meaningful for unordered_multiset
    // as the order is not defined. Equality (==) checks if they contain the same elements with the same counts.
    // if (umset8 < umset2) {
    //     std::cout << "umset8 is lexicographically less than umset2 (not well-defined for unordered_multiset)" << std::endl;
    // } else {
    //     std::cout << "umset8 is not lexicographically less than umset2 (not well-defined for unordered_multiset)" << std::endl;
    // }

    if (umset2 == umset9) {
        std::cout << "umset2 and umset9 are equal" << std::endl;
    } else {
        std::cout << "umset2 and umset9 are not equal (different counts of elements)" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through umset3 using range-based for loop: ";
    for (const std::string& str : umset3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // 10. Hashing and Buckets (Optional)
    std::cout << "\n// 10. Hashing and Buckets" << std::endl;
    std::cout << "Number of buckets in umset2: " << umset2.bucket_count() << std::endl;
    std::cout << "Load factor of umset2: " << umset2.load_factor() << std::endl;
    std::cout << "Max load factor of umset2: " << umset2.max_load_factor() << std::endl;

    return 0;
}