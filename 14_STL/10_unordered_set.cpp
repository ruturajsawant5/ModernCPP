#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::unordered_set<std::string> uset1;                      // Empty unordered_set
    std::unordered_set<std::string> uset2 = {"apple", "banana", "cherry"}; // Initialized with an initializer list
    std::unordered_set<std::string> uset3{"dog", "cat", "elephant"};       // Uniform initialization
    std::unordered_set<std::string> uset4(uset2.begin(), uset2.end()); // Initialize from iterators
    std::unordered_set<std::string> uset5;
    uset5.insert({"grape", "kiwi", "mango"}); // Inserting multiple elements

    std::cout << "uset2: ";
    for (const std::string& str : uset2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "uset5 after inserting multiple elements: ";
    for (const std::string& str : uset5) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    uset1.insert("one");
    uset1.insert("two");
    uset1.insert("three");
    uset1.insert("one"); // Duplicate element, will not be inserted

    std::cout << "uset1 after insertions: ";
    for (const std::string& str : uset1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    auto result = uset1.insert("four");
    if (result.second) {
        std::cout << "Inserted element: " << *result.first << std::endl;
    } else {
        std::cout << "Element not inserted (already exists): " << *result.first << std::endl;
    }

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements in uset2 (iterating): ";
    for (const std::string& str : uset2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    // Note: std::unordered_set does not provide direct access usingor at() because the order of elements is not guaranteed.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "uset2.size(): " << uset2.size() << std::endl;   // Returns the number of elements
    std::cout << "uset2.empty(): " << uset2.empty() << std::endl; // Returns true if the unordered_set is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    uset3.erase("cat"); // Erase element with value "cat"
    std::cout << "uset3 after erasing \"cat\": ";
    for (const std::string& str : uset3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    size_t count = uset3.erase("lion"); // Try to erase an element that doesn't exist
    std::cout << "Number of elements erased (value \"lion\"): " << count << std::endl;

    auto it_erase = uset3.find("dog");
    if (it_erase != uset3.end()) {
        uset3.erase(it_erase); // Erase element using an iterator
        std::cout << "uset3 after erasing \"dog\" using iterator: ";
        for (const std::string& str : uset3) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    uset1.clear(); // Removes all elements from the unordered_set
    std::cout << "uset1 after clear(): size = " << uset1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (uset2.find("banana") != uset2.end()) {
        std::cout << "Element \"banana\" found in uset2" << std::endl;
    } else {
        std::cout << "Element \"banana\" not found in uset2" << std::endl;
    }

    if (uset2.count("apple") > 0) {
        std::cout << "Element \"apple\" is present in uset2 (count: " << uset2.count("apple") << ")" << std::endl;
    } else {
        std::cout << "Element \"apple\" is not present in uset2" << std::endl;
    }

    // Note: unordered_set does not provide lower_bound, upper_bound, or equal_range as it's not ordered.

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through uset4 using iterators: ";
    for (auto it = uset4.begin(); it != uset4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Note: unordered_set iterators are forward iterators. There are no reverse iterators.

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::unordered_set<std::string> uset6 = {"apple", "banana", "cherry"};
    std::unordered_set<std::string> uset7 = {"banana", "apple", "cherry"};
    std::unordered_set<std::string> uset8 = {"apple", "banana"};

    if (uset2 == uset6) {
        std::cout << "uset2 and uset6 are equal" << std::endl;
    } else {
        std::cout << "uset2 and uset6 are not equal" << std::endl;
    }

    if (uset2 == uset7) {
        std::cout << "uset2 and uset7 are equal (order doesn't matter for unordered_set equality)" << std::endl;
    } else {
        std::cout << "uset2 and uset7 are not equal" << std::endl;
    }

//    if (uset8 < uset2) {
//        std::cout << "uset8 is lexicographically less than uset2 (not well-defined for unordered_set)" << std::endl;
//    } else {
//        std::cout << "uset8 is not lexicographically less than uset2 (not well-defined for unordered_set)" << std::endl;
//    }
    // Note: Comparison operators like <, >, <=, >= are generally not meaningful for unordered_set as the order is not defined. Equality (==) checks if they contain the same elements.

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through uset3 using range-based for loop: ";
    for (const std::string& str : uset3) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // 10. Hashing and Buckets (Optional)
    std::cout << "\n// 10. Hashing and Buckets" << std::endl;
    std::cout << "Number of buckets in uset2: " << uset2.bucket_count() << std::endl;
    std::cout << "Load factor of uset2: " << uset2.load_factor() << std::endl;
    std::cout << "Max load factor of uset2: " << uset2.max_load_factor() << std::endl;

    return 0;
}