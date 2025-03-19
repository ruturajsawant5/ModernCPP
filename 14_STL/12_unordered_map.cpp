#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::unordered_map<std::string, int> umap1;                      // Empty unordered_map
    std::unordered_map<std::string, int> umap2 = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    }; // Initialized with an initializer list of key-value pairs
    std::unordered_map<std::string, int> umap3{
        {"dog", 4},
        {"cat", 5},
        {"elephant", 6}
    }; // Uniform initialization
    std::unordered_map<std::string, int> umap4(umap2.begin(), umap2.end()); // Initialize from iterators
    std::unordered_map<std::string, int> umap5;
    umap5.insert({{"grape", 7}, {"kiwi", 8}}); // Inserting multiple key-value pairs

    std::cout << "umap2: ";
    for (const auto& pair : umap2) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    std::cout << "umap5 after inserting multiple pairs: ";
    for (const auto& pair : umap5) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    umap1["one"] = 1; // Using the subscript operator (creates entry if it doesn't exist)
    umap1.insert(std::pair<std::string, int>("two", 2));
    umap1.insert(std::make_pair("three", 3));
    umap1.insert({"four", 4}); // Using initializer list directly
    umap1.emplace("five", 5);    // Constructs the pair in-place

    std::cout << "umap1 after insertions: ";
    for (const auto& pair : umap1) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    auto result = umap1.insert({"one", 11}); // Inserting an existing key
    if (result.second) {
        std::cout << "Inserted element: [" << result.first->first << ": " << result.first->second << "]" << std::endl;
    } else {
        std::cout << "Element not inserted (key already exists): [" << result.first->first << ": " << result.first->second << "]" << std::endl;
    }

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "umap2[\"banana\"]: " << umap2["banana"] << std::endl; // Using subscript operator (creates entry if key doesn't exist)
    std::cout << "umap2.at(\"cherry\"): " << umap2.at("cherry") << std::endl; // Using at() method (throws exception if key doesn't exist)

    try {
        std::cout << "umap2.at(\"grape\"): " << umap2.at("grape") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "umap2.size(): " << umap2.size() << std::endl;   // Returns the number of key-value pairs
    std::cout << "umap2.empty(): " << umap2.empty() << std::endl; // Returns true if the unordered_map is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    umap3.erase("cat"); // Erase element with key "cat"
    std::cout << "umap3 after erasing \"cat\": ";
    for (const auto& pair : umap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    size_t count_erase = umap3.erase("lion"); // Try to erase a key that doesn't exist
    std::cout << "Number of elements erased (key \"lion\"): " << count_erase << std::endl;

    auto it_erase = umap3.find("dog");
    if (it_erase != umap3.end()) {
        umap3.erase(it_erase); // Erase element using an iterator
        std::cout << "umap3 after erasing \"dog\" using iterator: ";
        for (const auto& pair : umap3) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }

    umap1.clear(); // Removes all elements from the unordered_map
    std::cout << "umap1 after clear(): size = " << umap1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (umap2.find("banana") != umap2.end()) {
        std::cout << "Key \"banana\" found in umap2, value: " << umap2.find("banana")->second << std::endl;
    } else {
        std::cout << "Key \"banana\" not found in umap2" << std::endl;
    }

    if (umap2.count("apple") > 0) {
        std::cout << "Key \"apple\" is present in umap2 (count: " << umap2.count("apple") << ")" << std::endl;
    } else {
        std::cout << "Key \"apple\" is not present in umap2" << std::endl;
    }

    // Note: unordered_map does not provide lower_bound, upper_bound, or equal_range as it's not ordered.

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through umap4 using iterators: ";
    for (auto it = umap4.begin(); it != umap4.end(); ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;
    // The order of elements in an unordered_map is not guaranteed.

    // Note: unordered_map iterators are forward iterators. There are no reverse iterators.

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::unordered_map<std::string, int> umap6 = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    std::unordered_map<std::string, int> umap7 = {{"banana", 2}, {"apple", 1}, {"cherry", 3}};
    std::unordered_map<std::string, int> umap8 = {{"apple", 1}, {"banana", 2}};

    if (umap2 == umap6) {
        std::cout << "umap2 and umap6 are equal" << std::endl;
    } else {
        std::cout << "umap2 and umap6 are not equal" << std::endl;
    }

    if (umap2 == umap7) {
        std::cout << "umap2 and umap7 are equal (order doesn't matter for unordered_map equality)" << std::endl;
    } else {
        std::cout << "umap2 and umap7 are not equal" << std::endl;
    }

    // Comparison operators like <, >, <=, >= are generally not meaningful for unordered_map
    // as the order is not defined. Equality (==) checks if they contain the same key-value pairs.
    // if (umap8 < umap2) {
    //     std::cout << "umap8 is lexicographically less than umap2 (not well-defined for unordered_map)" << std::endl;
    // } else {
    //     std::cout << "umap8 is not lexicographically less than umap2 (not well-defined for unordered_map)" << std::endl;
    // }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through umap3 using range-based for loop: ";
    for (const auto& pair : umap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 10. Hashing and Buckets (Optional)
    std::cout << "\n// 10. Hashing and Buckets" << std::endl;
    std::cout << "Number of buckets in umap2: " << umap2.bucket_count() << std::endl;
    std::cout << "Load factor of umap2: " << umap2.load_factor() << std::endl;
    std::cout << "Max load factor of umap2: " << umap2.max_load_factor() << std::endl;

    return 0;
}