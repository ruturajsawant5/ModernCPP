#include <iostream>
#include <fstream>
#include <string>

void Read()
{
    //std::ifstream input{ "data.txt" };
    //OR
    std::ifstream input;
    input.open("data.txt");
    std::string message;
    int x;

    std::getline(input, message);
    input >> x;

    std::cout << message << " " << x << std::endl;

    input.close();
}

void Write()
{
    //std::ofstream output{ "data.txt" };
    //OR
    std::ofstream output;
    output.open("data.txt");
    output << "Hello World!" << std::endl;
    output << 10;
    output.close();
}

int main()
{
    Write();
    Read();
    return 0;
}