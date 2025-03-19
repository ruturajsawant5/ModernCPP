#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::unordered_multimap<std::string, int> ummap1;                      // Empty unordered_multimap
    std::unordered_multimap<std::string, int> ummap2 = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3},
        {"apple", 11} // Duplicate key allowed
    }; // Initialized with an initializer list of key-value pairs
    std::unordered_multimap<std::string, int> ummap3{
        {"dog", 4},
        {"cat", 5},
        {"elephant", 6},
        {"dog", 44} // Duplicate key allowed
    }; // Uniform initialization
    std::unordered_multimap<std::string, int> ummap4(ummap2.begin(), ummap2.end()); // Initialize from iterators
    std::unordered_multimap<std::string, int> ummap5;
    ummap5.insert({{"grape", 7}, {"kiwi", 8}, {"grape", 77}}); // Inserting multiple key-value pairs

    std::cout << "ummap2: ";
    for (const auto& pair : ummap2) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    std::cout << "ummap5 after inserting multiple pairs (including duplicates): ";
    for (const auto& pair : ummap5) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    ummap1.insert(std::pair<std::string, int>("one", 1));
    ummap1.insert(std::make_pair("two", 2));
    ummap1.insert({"three", 3}); // Using initializer list directly
    ummap1.emplace("four", 4);    // Constructs the pair in-place
    ummap1.insert({"one", 11}); // Inserting a duplicate key

    std::cout << "ummap1 after insertions (duplicates allowed): ";
    for (const auto& pair : ummap1) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    auto it_insert = ummap1.insert({"one", 12});
    std::cout << "Inserted element: [" << it_insert->first << ": " << it_insert->second << "]" << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements with key \"apple\" in ummap2 (iterating): ";
    for (auto it = ummap2.find("apple"); it != ummap2.end() && it->first == "apple"; ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;
    // Note: std::unordered_multimap does not provide direct access usingor at() because keys are not necessarily unique.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "ummap2.size(): " << ummap2.size() << std::endl;   // Returns the number of key-value pairs (including duplicates)
    std::cout << "ummap2.empty(): " << ummap2.empty() << std::endl; // Returns true if the unordered_multimap is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    ummap3.erase("dog"); // Erase all elements with key "dog"
    std::cout << "ummap3 after erasing \"dog\": ";
    for (const auto& pair : ummap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    size_t count_erase = ummap3.erase("lion"); // Try to erase a key that doesn't exist
    std::cout << "Number of elements erased (key \"lion\"): " << count_erase << std::endl;

    auto it_erase = ummap3.find("cat");
    if (it_erase != ummap3.end()) {
        ummap3.erase(it_erase); // Erase only the first occurrence of the key using an iterator
        std::cout << "ummap3 after erasing \"cat\" using iterator: ";
        for (const auto& pair : ummap3) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }

    ummap1.clear(); // Removes all elements from the unordered_multimap
    std::cout << "ummap1 after clear(): size = " << ummap1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (ummap2.find("banana") != ummap2.end()) {
        std::cout << "Key \"banana\" found in ummap2, value: " << ummap2.find("banana")->second << std::endl;
    } else {
        std::cout << "Key \"banana\" not found in ummap2" << std::endl;
    }

    std::cout << "Count of key \"apple\" in ummap2: " << ummap2.count("apple") << std::endl;
    std::cout << "Count of key \"cherry\" in ummap2: " << ummap2.count("cherry") << std::endl;

    // Note: unordered_multimap does not provide lower_bound, upper_bound, or equal_range as it's not ordered.

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through ummap4 using iterators: ";
    for (auto it = ummap4.begin(); it != ummap4.end(); ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;
    // The order of elements in an unordered_multimap is not guaranteed.

    // Note: unordered_multimap iterators are forward iterators. There are no reverse iterators.

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::unordered_multimap<std::string, int> ummap6 = {{"apple", 1}, {"banana", 2}, {"cherry", 3}, {"apple", 11}};
    std::unordered_multimap<std::string, int> ummap7 = {{"banana", 2}, {"apple", 1}, {"cherry", 3}, {"apple", 11}};
    std::unordered_multimap<std::string, int> ummap8 = {{"apple", 1}, {"banana", 2}};
    std::unordered_multimap<std::string, int> ummap9 = {{"apple", 1}, {"banana", 2}, {"apple", 11}};

    if (ummap2 == ummap6) {
        std::cout << "ummap2 and ummap6 are equal" << std::endl;
    } else {
        std::cout << "ummap2 and ummap6 are not equal" << std::endl;
    }

    if (ummap2 == ummap7) {
        std::cout << "ummap2 and ummap7 are equal (order doesn't matter, but counts do)" << std::endl;
    } else {
        std::cout << "ummap2 and ummap7 are not equal" << std::endl;
    }

    // Comparison operators like <, >, <=, >= are generally not meaningful for unordered_multimap
    // as the order is not defined. Equality (==) checks if they contain the same key-value pairs with the same counts.
    // if (ummap8 < ummap2) {
    //     std::cout << "ummap8 is lexicographically less than ummap2 (not well-defined for unordered_multimap)" << std::endl;
    // } else {
    //     std::cout << "ummap8 is not lexicographically less than ummap2 (not well-defined for unordered_multimap)" << std::endl;
    // }

    if (ummap2 == ummap9) {
        std::cout << "ummap2 and ummap9 are equal" << std::endl;
    } else {
        std::cout << "ummap2 and ummap9 are not equal (different counts of key-value pairs)" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through ummap3 using range-based for loop: ";
    for (const auto& pair : ummap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 10. Hashing and Buckets (Optional)
    std::cout << "\n// 10. Hashing and Buckets" << std::endl;
    std::cout << "Number of buckets in ummap2: " << ummap2.bucket_count() << std::endl;
    std::cout << "Load factor of ummap2: " << ummap2.load_factor() << std::endl;
    std::cout << "Max load factor of ummap2: " << ummap2.max_load_factor() << std::endl;

    return 0;
}