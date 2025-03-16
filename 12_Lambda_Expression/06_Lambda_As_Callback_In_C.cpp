#include <iostream>

int main()
{
    //SHOULD BE PARAMS IN CAPTURE LIST
    atexit([]() {
        std::cout << "Program is exitting..." << std::endl;
    });

    return 0;
}