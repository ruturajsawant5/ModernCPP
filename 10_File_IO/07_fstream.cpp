#include <iostream>
#include <fstream>
#include <string>

void do_file_io()
{
    std::fstream file;
    file.open("test.txt");
    if(!file)
    {
        std::ofstream out("test.txt");
        out.close();
        file.open("test.txt");
    }

    file << "Hello World!\n";

    file.seekg(0, std::ios::beg);

    char ch{};
    while(file.get(ch))
        std::cout << ch;

    std::cout << std::endl;

    file.close();
}

int main()
{
    do_file_io();
}