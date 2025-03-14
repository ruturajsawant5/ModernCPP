#include <iostream>
#include <fstream>
#include <string>

void Read()
{
    std::ifstream input;
    input.open("data.txt");
    std::string message;
    int x;

    std::getline(input, message);
    input >> x;

    int y;
    input >> y;
    if(input.eof())
        std::cout << "EOF Bit is Set" << std::endl;

    std::cout << message << " " << x << std::endl;

    input.close();
}

void Read2()
{
    std::ifstream input;
    input.open("data1.txt");
    if(input.fail())
        std::cout << "Fail Bit is Set" << std::endl;
    input.clear();
    input.setstate(std::ios_base::goodbit);
    if(input.good())
        std::cout << "Good Bit is Set Manually" << std::endl;
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

    output << "Hello World!" << std::endl;
    if(output.good())
        std::cout << "GOOD Bit Set" << std::endl;
    output << 10;
    if(output.bad())
        std::cout << "BAD Bit Set" << std::endl;
    output.close();
}

int main()
{
    Write();
    Read();
    Read2();
    return 0;
}