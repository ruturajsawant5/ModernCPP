#include <iostream>
#include <vector>
#include <algorithm>

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Prepare a sorted vector
    std::vector<int> sorted_nums = {1, 2, 2, 3, 4, 4, 4, 5, 6};
    int search_value = 4;

    std::cout << "// binary_search: Checks if a value exists in a sorted range (returns true or false)." << std::endl;
    std::cout << "// Permutation 1: Searching for an existing value" << std::endl;
    bool found = std::binary_search(sorted_nums.begin(), sorted_nums.end(), search_value);
    std::cout << search_value << " found: " << std::boolalpha << found << std::endl;
    std::cout << "// Permutation 2: Searching for a non-existing value" << std::endl;
    found = std::binary_search(sorted_nums.begin(), sorted_nums.end(), 7);
    std::cout << "7 found: " << found << std::endl;
    std::cout << "// Permutation 3: Using a custom comparator (e.g., searching in descending order - requires the range to be sorted accordingly)" << std::endl;
    std::vector<int> sorted_desc = {6, 5, 4, 4, 4, 3, 2, 2, 1};
    found = std::binary_search(sorted_desc.begin(), sorted_desc.end(), search_value, std::greater<int>());
    std::cout << search_value << " found (descending): " << found << std::endl;
    std::cout << std::endl;

    std::cout << "// lower_bound: Returns an iterator to the first element in a sorted range that is NOT LESS THAN (i.e., >=) a specified value." << std::endl;
    std::cout << "// Permutation 1: Finding lower bound of " << search_value << std::endl;
    auto it_lower = std::lower_bound(sorted_nums.begin(), sorted_nums.end(), search_value);
    if (it_lower != sorted_nums.end()) {
        std::cout << "Lower bound of " << search_value << " found at: " << *it_lower << " (index: " << std::distance(sorted_nums.begin(), it_lower) << ")" << std::endl;
    }
    std::cout << "// Permutation 2: Finding lower bound of a non-existing value (e.g., 3.5)" << std::endl;
    auto it_lower_non_existing = std::lower_bound(sorted_nums.begin(), sorted_nums.end(), 3.5);
    if (it_lower_non_existing != sorted_nums.end()) {
        std::cout << "Lower bound of 3.5 would be at: " << *it_lower_non_existing << " (index: " << std::distance(sorted_nums.begin(), it_lower_non_existing) << ")" << std::endl;
    }
    std::cout << "// Permutation 3: Using a custom comparator (e.g., for a vector of pairs, sorted by the second element)" << std::endl;
    std::vector<std::pair<int, int>> pairs = {{1, 10}, {2, 20}, {3, 20}, {4, 30}};
    int search_pair_value = 20;
    auto it_lower_pair = std::lower_bound(pairs.begin(), pairs.end(), search_pair_value,[](const std::pair<int, int>& p, int val){
        return p.second < val;
    });
    if (it_lower_pair != pairs.end()) {
        std::cout << "Lower bound of " << search_pair_value << " in pairs (based on second element) found at: {" << it_lower_pair->first << ", " << it_lower_pair->second << "}" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// upper_bound: Returns an iterator to the first element in a sorted range that is GREATER THAN a specified value." << std::endl;
    std::cout << "// Permutation 1: Finding upper bound of " << search_value << std::endl;
    auto it_upper = std::upper_bound(sorted_nums.begin(), sorted_nums.end(), search_value);
    if (it_upper != sorted_nums.end()) {
        std::cout << "Upper bound of " << search_value << " found at: " << *it_upper << " (index: " << std::distance(sorted_nums.begin(), it_upper) << ")" << std::endl;
    }
    std::cout << "// Permutation 2: Finding upper bound of a non-existing value (e.g., 3.5)" << std::endl;
    auto it_upper_non_existing = std::upper_bound(sorted_nums.begin(), sorted_nums.end(), 3.5);
    if (it_upper_non_existing != sorted_nums.end()) {
        std::cout << "Upper bound of 3.5 would be at: " << *it_upper_non_existing << " (index: " << std::distance(sorted_nums.begin(), it_upper_non_existing) << ")" << std::endl;
    }
    std::cout << "// Permutation 3: Using a custom comparator (e.g., for a vector of pairs, sorted by the second element)" << std::endl;
    auto it_upper_pair = std::upper_bound(pairs.begin(), pairs.end(), search_pair_value,[](int val, const std::pair<int, int>& p){
        return val < p.second;
    });
    if (it_upper_pair != pairs.end()) {
        std::cout << "Upper bound of " << search_pair_value << " in pairs (based on second element) found at: {" << it_upper_pair->first << ", " << it_upper_pair->second << "}" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// equal_range: Returns a pair of iterators representing the range of elements in a sorted range that are equal to a specified value." << std::endl;
    std::cout << "// Permutation 1: Finding equal range of " << search_value << std::endl;
    auto range = std::equal_range(sorted_nums.begin(), sorted_nums.end(), search_value);
    if (range.first != range.second) {
        std::cout << "Equal range of " << search_value << " found from index " << std::distance(sorted_nums.begin(), range.first)
                  << " to " << std::distance(sorted_nums.begin(), range.second) - 1 << std::endl;
        std::cout << "Elements in the range: ";
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << search_value << " not found." << std::endl;
    }
    std::cout << "// Permutation 2: Finding equal range of a non-existing value (e.g., 7)" << std::endl;
    auto range_non_existing = std::equal_range(sorted_nums.begin(), sorted_nums.end(), 7);
    if (range_non_existing.first == range_non_existing.second) {
        std::cout << "Equal range of 7 is empty (not found)." << std::endl;
    }
    std::cout << "// Permutation 3: Using a custom comparator (e.g., for a vector of pairs, finding range with a specific second element)" << std::endl;
    //int search_pair_value = 20;
    auto range_pair = std::equal_range(
    pairs.begin(), pairs.end(), std::make_pair(0, search_pair_value),
    [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    }
);

    if (range_pair.first != range_pair.second) {
        std::cout << "Equal range of " << search_pair_value << " in pairs (based on second element) found." << std::endl;
        for (auto it = range_pair.first; it != range_pair.second; ++it) {
            std::cout << "{" << it->first << ", " << it->second << "} ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Equal range of " << search_pair_value << " in pairs not found." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}