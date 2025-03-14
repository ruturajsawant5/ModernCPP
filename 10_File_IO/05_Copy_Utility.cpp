#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

int main()
{
    std::filesystem::path src(std::filesystem::current_path());
    src /= "Src.txt";
    std::cout << src << std::endl;

    std::filesystem::path dst(std::filesystem::current_path());
    dst /= "Dst.txt";
    std::cout << dst << std::endl;

    std::ifstream input {src};
    if(!input)
    {
        std::cerr << "Failed to open file " << src.filename() << std::endl;
        return -1;
    }

    std::ofstream output {dst};
    if(!output)
    {
        std::cerr << "Failed to open file " << dst.filename() << std::endl;
        return -1;
    }

    std::string line;
    while(std::getline(input, line))
        output << line << std::endl;

    input.close();
    output.close();
    return 0;
}