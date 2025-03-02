#include <iostream>

int main()
{
    char buf[512];
    //std::cout << "What is your full name: " << std::endl;
    //std::cin >> buf;
    // only first word is taken
    //std::cout << "Your name is " << buf << std::endl;

    //Multi Word
    std::cout << "What is your full name: " << std::endl;
    std::cin.getline(buf, 512, '\n');
    std::cout << "Your name is " << buf << std::endl;

    return 0;
}
