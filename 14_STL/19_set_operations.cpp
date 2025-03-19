#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> set1 = {1, 3, 5, 7, 9};
    std::vector<int> set2 = {2, 4, 6, 8, 10};
    std::vector<int> set3 = {3, 6, 9, 12};
    std::vector<int> result;

    std::cout << "// merge: Merges two sorted ranges into a new sorted range." << std::endl;
    std::cout << "// Permutation 1: Merging set1 and set2 using default comparison" << std::endl;
    result.clear();
    std::merge(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 2: Merging in descending order (requires input sets to be sorted accordingly)" << std::endl;
    std::vector<int> set1_desc = {9, 7, 5, 3, 1};
    std::vector<int> set2_desc = {10, 8, 6, 4, 2};
    result.clear();
    std::merge(set1_desc.begin(), set1_desc.end(), set2_desc.begin(), set2_desc.end(), std::back_inserter(result), std::greater<int>());
    print(result);
    std::cout << std::endl;

    std::cout << "// inplace_merge: Merges two consecutive sorted sub-ranges within a single range." << std::endl;
    std::cout << "// Permutation 1: Merging two sorted parts of a vector" << std::endl;
    std::vector<int> merged_vec = {1, 3, 5, 2, 4, 6};
    std::sort(merged_vec.begin(), merged_vec.begin() + 3); // Sort the first part
    std::sort(merged_vec.begin() + 3, merged_vec.end());   // Sort the second part
    std::inplace_merge(merged_vec.begin(), merged_vec.begin() + 3, merged_vec.end());
    print(merged_vec);
    std::cout << std::endl;

    std::cout << "// includes: Checks if one sorted range is a sub-sequence of another." << std::endl;
    std::cout << "// Permutation 1: Checking if set3 is a subset of a combined set" << std::endl;
    std::vector<int> combined_set;
    std::set_union(set1.begin(), set1.end(), set3.begin(), set3.end(), std::back_inserter(combined_set));
    std::sort(combined_set.begin(), combined_set.end()); // Ensure it's sorted for includes
    bool is_subset = std::includes(combined_set.begin(), combined_set.end(), set3.begin(), set3.end());
    std::cout << "Combined set includes set3: " << std::boolalpha << is_subset << std::endl;
    std::cout << "// Permutation 2: Using a custom comparator (e.g., for descending order)" << std::endl;
    std::vector<int> combined_set_desc = {12, 9, 7, 5, 3, 1};
    std::vector<int> set3_desc = {9, 3};
    is_subset = std::includes(combined_set_desc.begin(), combined_set_desc.end(), set3_desc.begin(), set3_desc.end(), std::greater<int>());
    std::cout << "Combined set (desc) includes set3 (desc): " << is_subset << std::endl;
    std::cout << std::endl;

    std::cout << "// set_union: Computes the union of two sorted ranges." << std::endl;
    std::cout << "// Permutation 1: Union of set1 and set2" << std::endl;
    result.clear();
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 2: Union with a custom comparator (not typically needed for basic types, but shown for completeness - requires sorted input)" << std::endl;
    result.clear();
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result), std::less<int>());
    print(result);
    std::cout << std::endl;

    std::cout << "// set_intersection: Computes the intersection of two sorted ranges." << std::endl;
    std::cout << "// Permutation 1: Intersection of set1 and set3" << std::endl;
    result.clear();
    std::set_intersection(set1.begin(), set1.end(), set3.begin(), set3.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 2: Intersection with a custom comparator (for descending order)" << std::endl;
    result.clear();
    std::set_intersection(set1_desc.begin(), set1_desc.end(), set3_desc.begin(), set3_desc.end(), std::back_inserter(result), std::greater<int>());
    print(result);
    std::cout << std::endl;

    std::cout << "// set_difference: Computes the set difference of two sorted ranges (elements in the first but not the second)." << std::endl;
    std::cout << "// Permutation 1: Difference of set1 and set3" << std::endl;
    result.clear();
    std::set_difference(set1.begin(), set1.end(), set3.begin(), set3.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 2: Difference of set3 and set1" << std::endl;
    result.clear();
    std::set_difference(set3.begin(), set3.end(), set1.begin(), set1.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 3: Difference with a custom comparator (for descending order)" << std::endl;
    result.clear();
    std::set_difference(set1_desc.begin(), set1_desc.end(), set3_desc.begin(), set3_desc.end(), std::back_inserter(result), std::greater<int>());
    print(result);
    std::cout << std::endl;

    std::cout << "// set_symmetric_difference: Computes the symmetric difference of two sorted ranges (elements in either but not both)." << std::endl;
    std::cout << "// Permutation 1: Symmetric difference of set1 and set3" << std::endl;
    result.clear();
    std::set_symmetric_difference(set1.begin(), set1.end(), set3.begin(), set3.end(), std::back_inserter(result));
    print(result);
    std::cout << "// Permutation 2: Symmetric difference with a custom comparator (for descending order)" << std::endl;
    result.clear();
    std::set_symmetric_difference(set1_desc.begin(), set1_desc.end(), set3_desc.begin(), set3_desc.end(), std::back_inserter(result), std::greater<int>());
    print(result);
    std::cout << std::endl;

    return 0;
}