#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Helper function to print the contents of a string
void print(const std::string& str) {
    std::cout << str << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 2, 5};
    std::vector<int> nums2 = {4, 5, 6};
    std::vector<int> nums3 = {1, 2, 3, 4, 2, 5};
    std::string text = "hello world";
    std::string pattern = "world";
    std::vector<int> perm1 = {1, 2, 3};
    std::vector<int> perm2 = {3, 1, 2};
    std::vector<int> perm3 = {1, 2, 4};

    std::cout << "// for_each: Applies a function object to each element in a range." << std::endl;
    std::cout << "// Permutation 1: Using a lambda function" << std::endl;
    std::for_each(nums.begin(), nums.end(), [](int n){ std::cout << n * 2 << " "; });
    std::cout << std::endl;
    std::cout << "// Permutation 2: Using a regular function (not shown here, but possible)" << std::endl;
    std::cout << std::endl;

    std::cout << "// find: Returns an iterator to the first element in a range that is equal to a specified value." << std::endl;
    std::cout << "// Permutation 1: Finding an existing element" << std::endl;
    auto it_find = std::find(nums.begin(), nums.end(), 3);
    if (it_find != nums.end()) {
        std::cout << "Found: " << *it_find << std::endl;
    }
    std::cout << "// Permutation 2: Finding a non-existing element" << std::endl;
    it_find = std::find(nums.begin(), nums.end(), 10);
    if (it_find == nums.end()) {
        std::cout << "Not found" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// find_end: Searches for the last occurrence of a subsequence within a range." << std::endl;
    std::cout << "// Permutation 1: Finding a subsequence" << std::endl;
    auto it_find_end = std::find_end(text.begin(), text.end(), pattern.begin(), pattern.end());
    if (it_find_end != text.end()) {
        std::cout << "Pattern found at position: " << std::distance(text.begin(), it_find_end) << std::endl;
    }
    std::cout << "// Permutation 2: Finding a non-existing subsequence" << std::endl;
    std::string pattern2 = "xyz";
    it_find_end = std::find_end(text.begin(), text.end(), pattern2.begin(), pattern2.end());
    if (it_find_end == text.end()) {
        std::cout << "Pattern not found" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// find_first_of: Searches for the first occurrence of any of the elements from a second range within the first range." << std::endl;
    std::cout << "// Permutation 1: Finding the first occurrence of elements from nums2 in nums" << std::endl;
    auto it_find_first_of = std::find_first_of(nums.begin(), nums.end(), nums2.begin(), nums2.end());
    if (it_find_first_of != nums.end()) {
        std::cout << "First of found: " << *it_find_first_of << " at position: " << std::distance(nums.begin(), it_find_first_of) << std::endl;
    }
    std::cout << "// Permutation 2: Using a predicate for comparison (finding first odd number)" << std::endl;
    std::vector<int> odd_check = {1, 3, 5, 7, 9};
    auto it_find_first_of_pred = std::find_first_of(nums.begin(), nums.end(), odd_check.begin(), odd_check.end(),[](int a, int b){ return a == b; });
    if (it_find_first_of_pred != nums.end()) {
        std::cout << "First odd found: " << *it_find_first_of_pred << " at position: " << std::distance(nums.begin(), it_find_first_of_pred) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// adjacent_find: Searches for the first occurrence of two consecutive identical elements in a range." << std::endl;
    std::cout << "// Permutation 1: Finding adjacent equal elements" << std::endl;
    auto it_adjacent_find = std::adjacent_find(nums.begin(), nums.end());
    if (it_adjacent_find != nums.end()) {
        std::cout << "Adjacent equal elements found: " << *it_adjacent_find << " and " << *(it_adjacent_find + 1) << std::endl;
    }
    std::cout << "// Permutation 2: Finding adjacent elements satisfying a predicate (second is double the first)" << std::endl;
    auto it_adjacent_find_pred = std::adjacent_find(nums.begin(), nums.end(),[](int a, int b){ return b == 2 * a; });
    if (it_adjacent_find_pred != nums.end()) {
        std::cout << "Adjacent elements where second is double the first: " << *it_adjacent_find_pred << " and " << *(it_adjacent_find_pred + 1) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// count: Returns the number of elements in a range that are equal to a specified value." << std::endl;
    std::cout << "// Permutation 1: Counting occurrences of 2" << std::endl;
    int count_val = std::count(nums.begin(), nums.end(), 2);
    std::cout << "Count of 2: " << count_val << std::endl;
    std::cout << std::endl;

    std::cout << "// count_if: Returns the number of elements in a range for which a predicate is true." << std::endl;
    std::cout << "// Permutation 1: Counting even numbers" << std::endl;
    int count_even = std::count_if(nums.begin(), nums.end(),[](int n){ return n % 2 == 0; });
    std::cout << "Count of even numbers: " << count_even << std::endl;
    std::cout << std::endl;

    std::cout << "// mismatch: Returns a pair of iterators pointing to the first elements in two ranges that differ." << std::endl;
    std::cout << "// Permutation 1: Finding the first mismatch" << std::endl;
    auto it_mismatch = std::mismatch(nums.begin(), nums.end(), nums3.begin());
    if (it_mismatch.first == nums.end()) {
        std::cout << "No mismatch found" << std::endl;
    } else {
        std::cout << "First mismatch at: " << *it_mismatch.first << " (in nums) and " << *it_mismatch.second << " (in nums3)" << std::endl;
    }
    std::cout << "// Permutation 2: Finding the first mismatch using a predicate (comparing if elements are equal)" << std::endl;
    std::vector<int> nums4 = {1, 2, 5, 4, 2, 5};
    auto it_mismatch_pred = std::mismatch(nums.begin(), nums4.begin(), nums4.end(), std::equal_to<int>());
    if (it_mismatch_pred.first == nums.end()) {
        std::cout << "No mismatch found with predicate" << std::endl;
    } else {
        std::cout << "First mismatch with predicate at: " << *it_mismatch_pred.first << " (in nums) and " << *it_mismatch_pred.second << " (in nums4)" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// equal: Checks if two ranges are equal." << std::endl;
    std::cout << "// Permutation 1: Checking if nums and nums3 are equal" << std::endl;
    bool are_equal = std::equal(nums.begin(), nums.end(), nums3.begin());
    std::cout << "nums and nums3 are equal: " << std::boolalpha << are_equal << std::endl;
    std::cout << "// Permutation 2: Checking if nums and nums4 are equal using a predicate (comparing if elements are equal)" << std::endl;
    bool are_equal_pred = std::equal(nums.begin(), nums.end(), nums4.begin(), std::equal_to<int>());
    std::cout << "nums and nums4 are equal with predicate: " << are_equal_pred << std::endl;
    std::cout << std::endl;

    std::cout << "// is_permutation: Checks if one range is a permutation of another." << std::endl;
    std::cout << "// Permutation 1: Checking if perm2 is a permutation of perm1" << std::endl;
    bool is_perm = std::is_permutation(perm1.begin(), perm1.end(), perm2.begin());
    std::cout << "perm2 is a permutation of perm1: " << is_perm << std::endl;
    std::cout << "// Permutation 2: Checking if perm3 is a permutation of perm1" << std::endl;
    is_perm = std::is_permutation(perm1.begin(), perm1.end(), perm3.begin());
    std::cout << "perm3 is a permutation of perm1: " << is_perm << std::endl;
    std::cout << "// Permutation 3: Using a predicate for comparison (not strictly a permutation in terms of value, but satisfying a condition)" << std::endl;
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {2, 3, 4};
    bool is_perm_pred = std::is_permutation(vec1.begin(), vec1.end(), vec2.begin(),[](int a, int b){ return b == a + 1; });
    std::cout << "vec2 is a permutation of vec1 with predicate (b == a + 1): " << is_perm_pred << std::endl;
    std::cout << std::endl;

    std::cout << "// min_element: Returns an iterator to the smallest element in a range." << std::endl;
    std::cout << "// Permutation 1: Finding the minimum element" << std::endl;
    auto it_min = std::min_element(nums.begin(), nums.end());
    if (it_min != nums.end()) {
        std::cout << "Minimum element: " << *it_min << std::endl;
    }
    std::cout << std::endl;

    std::cout << "// max_element: Returns an iterator to the largest element in a range." << std::endl;
    std::cout << "// Permutation 1: Finding the maximum element" << std::endl;
    auto it_max = std::max_element(nums.begin(), nums.end());
    if (it_max != nums.end()) {
        std::cout << "Maximum element: " << *it_max << std::endl;
    }
    std::cout << std::endl;

    return 0;
}