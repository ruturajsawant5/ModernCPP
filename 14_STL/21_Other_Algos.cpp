#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::sort
#include <string>
#include <cmath> // For std::abs

// Helper function to print the contents of a vector
template <typename T>
void print(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Custom binary function for accumulate (e.g., multiplication)
int multiply(int a, int b) {
    return a * b;
}

// Custom binary function for accumulate with strings (concatenation)
std::string concatenate(const std::string& a, const std::string& b) {
    return a + b;
}

// Custom struct
struct Point {
    int x;
    int y;
};

// Custom binary function for accumulate with Point (sum of x coordinates)
Point accumulate_points(Point sum, const Point& p) {
    return {sum.x + p.x, sum.y + p.y};
}

// Custom comparison function for sorting Points (by x-coordinate)
bool comparePointsByX(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<std::string> words = {"hello", " ", "world", "!"};
    std::vector<Point> points = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << "// accumulate: Computes the sum (or other binary operation) of elements in a range." << std::endl;
    std::cout << "// Permutation 1: Summing integers using the default operation (addition)" << std::endl;
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    std::cout << "// Permutation 2: Multiplying integers using a custom binary function" << std::endl;
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, multiply);
    std::cout << "Product: " << product << std::endl;

    std::cout << "// Permutation 3: Concatenating strings using a custom binary function" << std::endl;
    std::string sentence = std::accumulate(words.begin(), words.end(), std::string(""), concatenate);
    std::cout << "Sentence: " << sentence << std::endl;

    std::cout << "// Permutation 4: Accumulating Point objects using a custom binary function" << std::endl;
    Point initial_sum = {0, 0};
    Point total_points = std::accumulate(points.begin(), points.end(), initial_sum, accumulate_points);
    std::cout << "Total Point (sum of x): {" << total_points.x << ", " << total_points.y << "}" << std::endl;
    std::cout << std::endl;

    std::cout << "// sort: Sorts elements in a range in ascending order by default." << std::endl;
    std::cout << "// Permutation 1: Sorting integers in ascending order" << std::endl;
    std::vector<int> unsorted_numbers = {5, 1, 4, 2, 8};
    std::sort(unsorted_numbers.begin(), unsorted_numbers.end());
    print(unsorted_numbers);

    std::cout << "// Permutation 2: Sorting integers in descending order using std::greater<int>" << std::endl;
    std::vector<int> unsorted_numbers_desc = {5, 1, 4, 2, 8};
    std::sort(unsorted_numbers_desc.begin(), unsorted_numbers_desc.end(), std::greater<int>());
    print(unsorted_numbers_desc);

    std::cout << "// Permutation 3: Sorting integers based on absolute value using a lambda comparator" << std::endl;
    std::vector<int> unsorted_abs = {-3, 1, -4, 2, -8};
    std::sort(unsorted_abs.begin(), unsorted_abs.end(), [] (int a, int b) {
        return std::abs(a) < std::abs(b);
    });
    print(unsorted_abs);

    std::cout << "// Permutation 4: Sorting a vector of pairs based on the second element using a lambda comparator" << std::endl;
    std::vector<std::pair<int, int>> pairs = {{3, 2}, {1, 4}, {4, 1}, {2, 3}};
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    for (const auto& pair : pairs) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    std::cout << "// Permutation 5: Sorting a subrange of a vector" << std::endl;
    std::vector<int> partially_unsorted = {5, 1, 4, 2, 8, 3, 9};
    std::sort(partially_unsorted.begin() + 1, partially_unsorted.begin() + 5); // Sort from the second element to the fifth
    print(partially_unsorted);

    std::cout << "// Permutation 6: Sorting a vector of custom structs using a custom comparison function" << std::endl;
    std::sort(points.begin(), points.end(), comparePointsByX);
    for (const auto& point : points) {
        std::cout << "{" << point.x << ", " << point.y << "} ";
    }
    std::cout << std::endl;

    return 0;
}