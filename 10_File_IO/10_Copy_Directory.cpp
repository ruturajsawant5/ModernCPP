#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iomanip>
#include <thread>

namespace fs = std::filesystem;

// Function to copy a file and show progress
void copy_file_with_progress(const fs::path& src, const fs::path& dst) {
    std::ifstream input(src, std::ios::binary);
    if (!input) {
        std::cerr << "Failed to open input file: " << src << std::endl;
        return;
    }

    std::ofstream output(dst, std::ios::binary);
    if (!output) {
        std::cerr << "Failed to open output file: " << dst << std::endl;
        return;
    }

    // Get the size of the source file
    input.seekg(0, std::ios::end);
    std::streampos file_size = input.tellg();
    input.seekg(0, std::ios::beg);

    // Buffer for reading the file in chunks
    const size_t buffer_size = 4096;
    char buffer[buffer_size];
    std::streampos bytes_read = 0;

    // Read and write the file in chunks
    while (input) {
        input.read(buffer, buffer_size);
        std::streamsize read_count = input.gcount();
        if (read_count > 0) {
            output.write(buffer, read_count);
            bytes_read += read_count;

            // Show progress
            int progress = static_cast<int>((static_cast<double>(bytes_read) / file_size) * 100);
            std::cout << "\rCopying " << src.filename() << ": " << progress << "%";
            std::cout.flush();
        }
    }

    std::cout << "\rCopying " << src.filename() << ": 100%" << std::endl;

    input.close();
    output.close();
}

// Function to copy all files in a directory
void copy_directory(const fs::path& src, const fs::path& dst) {
    // Create the target directory if it doesn't exist
    if (!fs::exists(dst)) {
        fs::create_directories(dst);
        std::cout << "Created directory: " << dst << std::endl;
    }

    // Iterate through all files in the source directory
    for (const auto& entry : fs::directory_iterator(src)) {
        const auto& src_path = entry.path();
        auto dst_path = dst / src_path.filename();

        if (fs::is_directory(src_path)) {
            // If it's a directory, recursively copy its contents
            copy_directory(src_path, dst_path);
        } else if (fs::is_regular_file(src_path)) {
            // If it's a regular file, copy it
            copy_file_with_progress(src_path, dst_path);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source> <destination>" << std::endl;
        return -1;
    }

    fs::path source(argv[1]);
    fs::path destination(argv[2]);

    // Check if source exists
    if (!fs::exists(source)) {
        std::cerr << "Error: Source path does not exist!" << std::endl;
        return -1;
    }

    // Check if source is a directory or a file
    if (fs::is_directory(source)) {
        std::cout << "Copying contents of directory: " << source << " to " << destination << std::endl;
        copy_directory(source, destination);
    } else if (fs::is_regular_file(source)) {
        std::cout << "Copying file: " << source << " to " << destination << std::endl;
        // Ensure the target file does not exist, or show a message
        if (fs::exists(destination)) {
            std::cerr << "Error: Target file already exists. Copy operation aborted." << std::endl;
            return -1;
        }
        copy_file_with_progress(source, destination);
    } else {
        std::cerr << "Error: Unsupported source type!" << std::endl;
        return -1;
    }

    return 0;
}
