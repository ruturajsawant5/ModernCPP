#include <iostream>
#include <string>

int main()
{
    std::string path { "C:\Users\Ruturaj" };
    std::cout << path << std::endl;
    //C:UsersRuturaj
    //\ treated as escape sequence

    std::string path2 { "C:\\Users\\Ruturaj" };
    std::cout << path2 << std::endl;
    //C:\Users\Ruturaj
    // solution \\ but tedious

    std::string path3 { R"(C:\Users\Ruturaj)" };
    std::cout << path3 << std::endl;

    //std::string path4 { R"(C:\Users\Ruturaj "(C++11)")" };

    //custom delimiter
    std::string path5 { R"CUSTOMDELIM(C:\Users\Ruturaj "(C++11)")CUSTOMDELIM" };
    std::cout << path5 << std::endl;

    return 0;
}