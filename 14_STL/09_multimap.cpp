#include <iostream>
#include <map>
#include <string>
#include <algorithm> // For std::find (though multimap has its own find)

int main() {
    // 1. Initialization
    std::cout << "// 1. Initialization" << std::endl;
    std::multimap<std::string, int> multimap1;                      // Empty multimap
    std::multimap<std::string, int> multimap2 = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3},
        {"apple", 11} // Duplicate key allowed
    }; // Initialized with an initializer list of key-value pairs
    std::multimap<std::string, int> multimap3{
        {"dog", 4},
        {"cat", 5},
        {"elephant", 6},
        {"dog", 44} // Duplicate key allowed
    }; // Uniform initialization
    std::multimap<std::string, int> multimap4(multimap2.begin(), multimap2.end()); // Initialize from iterators
    std::multimap<std::string, int> multimap5;
    multimap5.insert({{"grape", 7}, {"kiwi", 8}, {"grape", 77}}); // Inserting multiple key-value pairs

    std::cout << "multimap2: ";
    for (const auto& pair : multimap2) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    std::cout << "multimap5 after inserting multiple pairs (including duplicates): ";
    for (const auto& pair : multimap5) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    // 2. Adding Elements (Insertion)
    std::cout << "\n// 2. Adding Elements (Insertion)" << std::endl;
    multimap1.insert(std::pair<std::string, int>("one", 1));
    multimap1.insert(std::make_pair("two", 2));
    multimap1.insert({"three", 3}); // Using initializer list directly
    multimap1.emplace("four", 4);    // Constructs the pair in-place
    multimap1.insert({"one", 11}); // Inserting a duplicate key

    std::cout << "multimap1 after insertions (duplicates allowed): ";
    for (const auto& pair : multimap1) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    auto it_insert = multimap1.insert({"one", 12});
    std::cout << "Inserted element: [" << it_insert->first << ": " << it_insert->second << "]" << std::endl;

    // 3. Accessing Elements
    std::cout << "\n// 3. Accessing Elements" << std::endl;
    std::cout << "Elements with key \"apple\" in multimap2 (iterating): ";
    for (auto it = multimap2.find("apple"); it != multimap2.end() && it->first == "apple"; ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;
    // Note: std::multimap does not provide direct access usingor at() because keys are not necessarily unique.

    // 4. Size
    std::cout << "\n// 4. Size" << std::endl;
    std::cout << "multimap2.size(): " << multimap2.size() << std::endl;   // Returns the number of key-value pairs (including duplicates)
    std::cout << "multimap2.empty(): " << multimap2.empty() << std::endl; // Returns true if the multimap is empty (size is 0)

    // 5. Removing Elements
    std::cout << "\n// 5. Removing Elements" << std::endl;
    multimap3.erase("dog"); // Erase all elements with key "dog"
    std::cout << "multimap3 after erasing \"dog\": ";
    for (const auto& pair : multimap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    size_t count_erase = multimap3.erase("lion"); // Try to erase a key that doesn't exist
    std::cout << "Number of elements erased (key \"lion\"): " << count_erase << std::endl;

    auto it_erase = multimap3.find("cat");
    if (it_erase != multimap3.end()) {
        multimap3.erase(it_erase); // Erase only the first occurrence of the key using an iterator
        std::cout << "multimap3 after erasing \"cat\" using iterator: ";
        for (const auto& pair : multimap3) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }

    multimap1.clear(); // Removes all elements from the multimap
    std::cout << "multimap1 after clear(): size = " << multimap1.size() << std::endl;

    // 6. Searching for Elements
    std::cout << "\n// 6. Searching for Elements" << std::endl;
    if (multimap2.find("banana") != multimap2.end()) {
        std::cout << "Key \"banana\" found in multimap2, value: " << multimap2.find("banana")->second << std::endl;
    } else {
        std::cout << "Key \"banana\" not found in multimap2" << std::endl;
    }

    std::cout << "Count of key \"apple\" in multimap2: " << multimap2.count("apple") << std::endl;
    std::cout << "Count of key \"cherry\" in multimap2: " << multimap2.count("cherry") << std::endl;

    auto it_lower = multimap2.lower_bound("apricot"); // Returns an iterator to the first element with key >= "apricot"
    if (it_lower != multimap2.end()) {
        std::cout << "Lower bound of \"apricot\" in multimap2: [" << it_lower->first << ": " << it_lower->second << "]" << std::endl;
    } else {
        std::cout << "Lower bound of \"apricot\" not found (all keys are less)" << std::endl;
    }

    auto it_upper = multimap2.upper_bound("apricot"); // Returns an iterator to the first element with key > "apricot"
    if (it_upper != multimap2.end()) {
        std::cout << "Upper bound of \"apricot\" in multimap2: [" << it_upper->first << ": " << it_upper->second << "]" << std::endl;
    } else {
        std::cout << "Upper bound of \"apricot\" not found (all keys are less or equal)" << std::endl;
    }

    auto range = multimap2.equal_range("apple"); // Returns a pair of iterators (lower_bound, upper_bound) for elements with key "apple"
    std::cout << "Elements with key \"apple\" in multimap2: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;

    // 7. Iterators
    std::cout << "\n// 7. Iterators" << std::endl;
    std::cout << "Iterating through multimap4 using iterators: ";
    for (auto it = multimap4.begin(); it != multimap4.end(); ++it) {
        std::cout << "[" << it->first << ": " << it->second << "] ";
    }
    std::cout << std::endl;

    std::cout << "Iterating through multimap4 using reverse iterators: ";
    for (auto rit = multimap4.rbegin(); rit != multimap4.rend(); ++rit) {
        std::cout << "[" << rit->first << ": " << rit->second << "] ";
    }
    std::cout << std::endl;

    // 8. Comparison
    std::cout << "\n// 8. Comparison" << std::endl;
    std::multimap<std::string, int> multimap6 = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    std::multimap<std::string, int> multimap7 = {{"banana", 2}, {"apple", 1}, {"cherry", 3}};
    std::multimap<std::string, int> multimap8 = {{"apple", 1}, {"banana", 2}};
    std::multimap<std::string, int> multimap9 = {{"apple", 1}, {"banana", 2}, {"apple", 11}};

    if (multimap2 == multimap9) {
        std::cout << "multimap2 and multimap9 are equal" << std::endl;
    } else {
        std::cout << "multimap2 and multimap9 are not equal" << std::endl;
    }

    if (multimap6 != multimap7) {
        std::cout << "multimap6 and multimap7 are not equal (order matters for equality)" << std::endl;
    } else {
        std::cout << "multimap6 and multimap7 are equal" << std::endl;
    }

    if (multimap8 < multimap2) {
        std::cout << "multimap8 is lexicographically less than multimap2" << std::endl;
    } else {
        std::cout << "multimap8 is not lexicographically less than multimap2" << std::endl;
    }

    // 9. Range-based for loop
    std::cout << "\n// 9. Range-based for loop" << std::endl;
    std::cout << "Iterating through multimap3 using range-based for loop: ";
    for (const auto& pair : multimap3) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;

    return 0;
}