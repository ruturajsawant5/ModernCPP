#include <iostream>
#include <fstream>
#include <string>

void Read()
{
    std::ifstream input;
    input.open("data.txt");
    if(!input.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return;
    }

    char ch{};

    while(input.get(ch))
        std::cout << ch;

    std::cout << input.tellg() << std::endl;

	input.clear();

    input.seekg(0, std::ios::beg);

    std::cout << input.tellg() << std::endl;
    while(input.get(ch))
        std::cout << ch;

    input.close();
}

void Write()
{
    std::ofstream output;
    output.open("data.txt");
    if(!output.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return;
    }

    std::string message{ "lorem ipsum dolor sit amet" };

    for(char x : message)
        output.put(x);

    std::cout << output.tellp() << std::endl;

    output.clear();

    output.seekp(0, std::ios::beg);

    std::string msg {"WORLD"};
    for(char x : msg)
        output.put(x);

    output.close();
}

int main()
{
    Write();
    Read();
    return 0;
}