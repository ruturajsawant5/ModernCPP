#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

int main()
{
    // Define the source and destination file paths using filesystem library
    std::filesystem::path src(std::filesystem::current_path());
    src /= "Src.bin";  // Change to your actual binary source file name
    std::cout << "Source file: " << src << std::endl;

    std::filesystem::path dst(std::filesystem::current_path());
    dst /= "Dst.bin";  // Change to your desired binary destination file name
    std::cout << "Destination file: " << dst << std::endl;

    // Check if the destination file already exists to prevent overwriting
    if (std::filesystem::exists(dst)) {
        std::cerr << "Error: The file " << dst.filename() << " already exists. Copy operation aborted." << std::endl;
        return -1;
    }

    // Open the source file in binary mode
    std::ifstream input(src, std::ios::binary);
    if (!input) {
        std::cerr << "Failed to open file " << src.filename() << std::endl;
        return -1;
    }

    // Open the destination file in binary mode
    std::ofstream output(dst, std::ios::binary);
    if (!output) {
        std::cerr << "Failed to open file " << dst.filename() << std::endl;
        return -1;
    }

    // Get the size of the source file
    input.seekg(0, std::ios::end);        // Move to the end of the file
    std::streampos file_size = input.tellg();  // Get the file size
    input.seekg(0, std::ios::beg);        // Move back to the beginning of the file

    // Set buffer size for reading chunks
    const size_t buffer_size = 4096;
    char buffer[buffer_size];

    // Read the source file and write to the destination file in chunks
    while (file_size > 0) {
        size_t bytes_to_read = (file_size > buffer_size) ? buffer_size : static_cast<size_t>(file_size);

        // Read data into buffer
        input.read(buffer, bytes_to_read);

        // Check for any read error
        if (!input) {
            std::cerr << "Error reading the source file!" << std::endl;
            input.close();
            output.close();
            return -1;
        }

        // Write the bytes read into the destination file
        output.write(buffer, input.gcount());

        // Check for any write error
        if (!output) {
            std::cerr << "Error writing to the destination file!" << std::endl;
            input.close();
            output.close();
            return -1;
        }

        // Update remaining size of the file
        file_size -= input.gcount();
    }

    std::cout << "File copy completed successfully!" << std::endl;

    // Close the files
    input.close();
    output.close();
    return 0;
}
