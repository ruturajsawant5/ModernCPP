#include <iostream>
#include <map>
#include <string>
#include <algorithm> // For std::find (though map has its own find)

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::map<std::string, int> map1;                      // Empty map
    std::map<std::string, int> map2 = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    }; // Initialized with an initializer list of key-value pairs
    std::map<std::string, int> map3{
        {"dog", 4},
        {"cat", 5},
        {"elephant", 6}
    }; // Uniform initialization
    std::map<std::string, int> map4(map2.begin(), map2.end()); // Initialize from iterators
    std::map<std::string, int> map5;
    map5.insert({{"grape", 7}, {"kiwi", 8}}); // Inserting multiple key-value pairs

    std::cout << "map2: ";
    for (const auto& pair : map2) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    std::cout << "map5 after inserting multiple pairs: ";
    for (const auto& pair : map5) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    map1["one"] = 1; // Using the subscript operator (creates entry if it doesn't exist)
    map1.insert(std::pair<std::string, int>("two", 2));
    map1.insert(std::make_pair("three", 3));
    map1.insert({"four", 4}); // Using initializer list directly
    map1.emplace("five", 5);    // Constructs the pair in-place

    std::cout << "map1 after insertions: ";
    for (const auto& pair : map1) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    auto result = map1.insert({"one", 11}); // Inserting an existing key
    if (result.second) {
        std::cout << "Inserted element: [" << result.first->first << ": " << result.first->second << "]" << std::endl;
    } else {
        std::cout << "Element not inserted (key already exists): [" << result.first->first << ": " << result.first->second << "]" << std::endl;
    }

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "map2[\"banana\"]: " << map2["banana"] << std::endl; // Using subscript operator (creates entry if key doesn't exist)
    std::cout << "map2.at(\"cherry\"): " << map2.at("cherry") << std::endl; // Using at() method (throws exception if key doesn't exist)

    try {
        std::cout << "map2.at(\"grape\"): " << map2.at("grape") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "map2.size(): " << map2.size() << std::endl;   // Returns the number of key-value pairs
    std::cout << "map2.empty(): " << map2.empty() << std::endl; // Returns true if the map is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    map3.erase("cat"); // Erase element with key "cat"
    std::cout << "map3 after erasing \"cat\": ";
    for (const auto& pair : map3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    size_t count_erase = map3.erase("lion"); // Try to erase a key that doesn't exist
    std::cout << "Number of elements erased (key \"lion\"): " << count_erase << std::endl;

    auto it_erase = map3.find("dog");
    if (it_erase != map3.end()) {
        map3.erase(it_erase); // Erase element using an iterator
        std::cout << "map3 after erasing \"dog\" using iterator: ";
        for (const auto& pair : map3) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }

    map1.clear(); // Removes all elements from the map
    std::cout << "map1 after clear(): size = " << map1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (map2.find("banana") != map2.end()) {
        std::cout << "Key \"banana\" found in map2, value: " << map2.find("banana")->second << std::endl;
    } else {
        std::cout << "Key \"banana\" not found in map2" << std::endl;
    }

    if (map2.count("apple") > 0) {
        std::cout << "Key \"apple\" is present in map2 (count: " << map2.count("apple") << ")" << std::endl;
    } else {
        std::cout << "Key \"apple\" is not present in map2" << std::endl;
    }

    auto it_lower = map2.lower_bound("apricot"); // Returns an iterator to the first element with key >= "apricot"
    if (it_lower != map2.end()) {
        std::cout << "Lower bound of \"apricot\" in map2: [" << it_lower->first << ": " << it_lower->second << "]" << std::endl;
    } else {
        std::cout << "Lower bound of \"apricot\" not found (all keys are less)" << std::endl;
    }

    auto it_upper = map2.upper_bound("apricot"); // Returns an iterator to the first element with key > "apricot"
    if (it_upper != map2.end()) {
        std::cout << "Upper bound of \"apricot\" in map2: [" << it_upper->first << ": " << it_upper->second << "]" << std::endl;
    } else {
        std::cout << "Upper bound of \"apricot\" not found (all keys are less or equal)" << std::endl;
    }

    auto range = map2.equal_range("banana"); // Returns a pair of iterators (lower_bound, upper_bound) for elements with key "banana"
    std::cout << "Elements with key \"banana\" in map2: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through map4 using iterators: ";
    for (auto it = map4.begin(); it != map4.end(); ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through map4 using reverse iterators: ";
    for (auto rit = map4.rbegin(); rit != map4.rend(); ++rit) {
        std::cout << "[" << rit->first << ": " << rit->second << "] ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::map<std::string, int> map6 = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    std::map<std::string, int> map7 = {{"banana", 2}, {"apple", 1}, {"cherry", 3}};
    std::map<std::string, int> map8 = {{"apple", 1}, {"banana", 2}};

    if (map2 == map6) {
        std::cout << "map2 and map6 are equal" << std::endl;
    } else {
        std::cout << "map2 and map6 are not equal" << std::endl;
    }

    if (map2 != map7) {
        std::cout << "map2 and map7 are not equal (order of insertion might differ, but content is the same)" << std::endl;
    } else {
        std::cout << "map2 and map7 are equal" << std::endl;
    }

    if (map8 < map2) {
        std::cout << "map8 is lexicographically less than map2" << std::endl;
    } else {
        std::cout << "map8 is not lexicographically less than map2" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through map3 using range-based for loop: ";
    for (const auto& pair : map3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    return 0;
}