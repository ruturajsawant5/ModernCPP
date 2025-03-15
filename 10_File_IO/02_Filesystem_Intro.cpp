#include <iostream>
#include <filesystem>
//cl /EHsc 02_Filesystem_Intro.cpp /std:c++17
int main()
{
    std::filesystem::path path1{R"(C:\Users\rutur\Documents\GITHUB\ModernCPP\10_File_IO\01_Raw_String_Literals.cpp)"};
    if(path1.has_filename())
        std::cout << path1.filename() << " Exists" << std::endl;
    else
        std::cout << path1.filename() << " Not Found" << std::endl;

    std::filesystem::path path2{R"(C:\Users\rutur\Documents\GITHUB\ModernCPP\10_File_IO\NOTANFILE.cpp)"};
    if(path2.has_filename())
        std::cout << path2.filename() << " Exists" << std::endl;
    else
        std::cout << path2.filename() << " Not Found" << std::endl;

    std::cout << "__________________________________" << std::endl;

    for (auto x : path1)
        std::cout << x << std::endl;

    std::filesystem::path path{R"(C:\Users\rutur\)"};
    std::filesystem::directory_iterator begin{path};
    std::filesystem::directory_iterator end{}; //sentinel value

    std::cout << "__________________________________" << std::endl;
    while (begin != end)
    {
        std::cout << *begin << std::endl;
        ++begin;
    }


    return 0;
}