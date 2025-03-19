#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> dest(nums.size());
    std::vector<int> source = {10, 20, 30};
    std::vector<int> results;
    std::string text = "hello";
    int replace_val = 3;
    int new_val = 30;
    int fill_value = 9;
    int n = 5;
    int start_value = 100;
    std::vector<int> duplicates = {1, 1, 2, 2, 3, 3, 1, 1};

    std::cout << "// copy: Copies elements from one range to another." << std::endl;
    std::cout << "// Permutation 1: Copying from nums to dest" << std::endl;
    std::copy(nums.begin(), nums.end(), dest.begin());
    print(dest);
    std::cout << std::endl;

    std::cout << "// move: Moves elements from one range to another." << std::endl;
    std::cout << "// Permutation 1: Moving from source to dest (source might be in an unspecified but valid state afterwards)" << std::endl;
    std::move(source.begin(), source.end(), dest.begin());
    print(dest);
    // source should not be relied upon after a move operation
    std::cout << std::endl;

    std::cout << "// transform: Applies a function to each element in a range." << std::endl;
    std::cout << "// Permutation 1: Using a lambda to multiply each element by 2" << std::endl;
    results.resize(nums.size());
    std::transform(nums.begin(), nums.end(), results.begin(), [](int n){ return n * 2; });
    print(results);
    std::cout << "// Permutation 2: Using a binary operation with another range (element-wise addition)" << std::endl;
    std::vector<int> add_vals = {10, 20, 30, 40, 50};
    results.resize(nums.size());
    std::transform(nums.begin(), nums.end(), add_vals.begin(), results.begin(),[](int a, int b){ return a + b; });
    print(results);
    std::cout << "// Permutation 3: Capturing a variable in the lambda" << std::endl;
    int offset = 5;
    results.resize(nums.size());
    std::transform(nums.begin(), nums.end(), results.begin(), [offset](int n){ return n + offset; });
    print(results);
    std::cout << std::endl;

    std::cout << "// replace: Replaces all occurrences of a specified value in a range with another value." << std::endl;
    std::cout << "// Permutation 1: Replacing all occurrences of 3 with 30" << std::endl;
    std::vector<int> replace_nums = nums;
    std::replace(replace_nums.begin(), replace_nums.end(), replace_val, new_val);
    print(replace_nums);
    std::cout << "// Permutation 2: Replacing elements based on a predicate (replace even numbers with -1)" << std::endl;
    replace_nums = nums;
    std::replace_if(replace_nums.begin(), replace_nums.end(),[](int n){ return n % 2 == 0; }, -1);
    print(replace_nums);
    std::cout << std::endl;

    std::cout << "// fill: Assigns a specified value to all elements in a range." << std::endl;
    std::cout << "// Permutation 1: Filling the 'dest' vector with 9" << std::endl;
    std::fill(dest.begin(), dest.end(), fill_value);
    print(dest);
    std::cout << std::endl;

    std::cout << "// generate: Assigns the result of a function object to each element in a range." << std::endl;
    std::cout << "// Permutation 1: Generating a sequence starting from 100" << std::endl;
    results.resize(n);
    std::generate(results.begin(), results.end(), [val = start_value]() mutable { return val++; });
    print(results);
    std::cout << "// Permutation 2: Using a simple function" << std::endl;
    auto generate_func = [count = 0]() mutable { return count++; };
    results.resize(n);
    std::generate(results.begin(), results.end(), generate_func);
    print(results);
    std::cout << std::endl;

    std::cout << "// remove: Removes all elements equal to a specified value from a range (returns iterator to the new end)." << std::endl;
    std::cout << "// Permutation 1: Removing all occurrences of 2" << std::endl;
    std::vector<int> remove_nums = nums;
    auto it_remove = std::remove(remove_nums.begin(), remove_nums.end(), 2);
    remove_nums.erase(it_remove, remove_nums.end()); // Need to erase the removed elements
    print(remove_nums);
    std::cout << "// Permutation 2: Removing elements based on a predicate (remove odd numbers)" << std::endl;
    remove_nums = nums;
    auto it_remove_if = std::remove_if(remove_nums.begin(), remove_nums.end(),[](int n){ return n % 2 != 0; });
    remove_nums.erase(it_remove_if, remove_nums.end());
    print(remove_nums);
    std::cout << std::endl;

    std::cout << "// unique: Removes consecutive duplicate elements from a range (returns iterator to the new end)." << std::endl;
    std::cout << "// Permutation 1: Removing consecutive duplicates" << std::endl;
    std::vector<int> unique_nums = duplicates;
    auto it_unique = std::unique(unique_nums.begin(), unique_nums.end());
    unique_nums.erase(it_unique, unique_nums.end());
    print(unique_nums);
    std::cout << "// Permutation 2: Removing consecutive elements based on a predicate (consider only even numbers unique)" << std::endl;
    std::vector<int> unique_nums_pred = {2, 4, 4, 6, 8, 8, 2};
    auto it_unique_pred = std::unique(unique_nums_pred.begin(), unique_nums_pred.end(),[](int a, int b){
        return a % 2 == 0 && b % 2 == 0;
    });
    unique_nums_pred.erase(it_unique_pred, unique_nums_pred.end());
    print(unique_nums_pred); // Output might not be as expected for this specific predicate
    std::cout << std::endl;

    std::cout << "// unique_copy: Copies unique elements from a range to another range." << std::endl;
    std::cout << "// Permutation 1: Copying unique elements from 'duplicates' to 'results'" << std::endl;
    results.resize(duplicates.size());
    auto it_unique_copy = std::unique_copy(duplicates.begin(), duplicates.end(), results.begin());
    results.resize(std::distance(results.begin(), it_unique_copy));
    print(results);
    std::cout << std::endl;

    std::cout << "// reverse: Reverses the order of elements in a range." << std::endl;
    std::cout << "// Permutation 1: Reversing the 'nums' vector" << std::endl;
    std::vector<int> reversed_nums = nums;
    std::reverse(reversed_nums.begin(), reversed_nums.end());
    print(reversed_nums);
    std::cout << std::endl;

    std::cout << "// rotate: Rotates the elements in a range." << std::endl;
    std::cout << "// Permutation 1: Rotating 'nums' so the element at index 2 (value 3) becomes the first" << std::endl;
    std::vector<int> rotated_nums = nums;
    std::rotate(rotated_nums.begin(), rotated_nums.begin() + 2, rotated_nums.end());
    print(rotated_nums);
    std::cout << std::endl;

    std::cout << "// shuffle: Randomly shuffles the elements in a range." << std::endl;
    std::cout << "// Permutation 1: Shuffling the 'nums' vector" << std::endl;
    std::vector<int> shuffled_nums = nums;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(shuffled_nums.begin(), shuffled_nums.end(), gen);
    print(shuffled_nums);
    std::cout << std::endl;

    return 0;
}