#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

enum class Case { SENSITIVE, INSENSITIVE };

size_t Find(
        const std::string &source,         // Source string to be searched
        const std::string &search_string,  // The string to search for
        Case searchCase = Case::INSENSITIVE, // Choose case-sensitive/insensitive search
        size_t offset = 0 ) {              // Start the search from this offset
    // Handle invalid offset
    if (offset >= source.size()) {
        return std::string::npos;
    }

    // Create a version of the source string to work with based on case sensitivity
    std::string search_source = source.substr(offset);  // Substring starting from offset

    if (searchCase == Case::INSENSITIVE) {
        // Convert both source and search string to lower case for case-insensitive comparison
        std::transform(search_source.begin(), search_source.end(), search_source.begin(), ::tolower);
        std::string search_lower = search_string;
        std::transform(search_lower.begin(), search_lower.end(), search_lower.begin(), ::tolower);

        // Find the search string in the transformed source string
        size_t found = search_source.find(search_lower);
        return found == std::string::npos ? std::string::npos : found + offset;
    }

    // Case-sensitive search
    size_t found = search_source.find(search_string);
    return found == std::string::npos ? std::string::npos : found + offset;
}

int main() {
    std::string text = "Hello, World!";
    std::string search_term = "world";

    size_t position = Find(text, search_term, Case::INSENSITIVE);
    if (position != std::string::npos) {
        std::cout << "Found at position: " << position << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}