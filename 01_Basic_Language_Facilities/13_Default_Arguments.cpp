#include <iostream>

void CreateWindow(const char * title, int x, int y, int width, int height);

void CreateWindow(const char * title, int x = -1, int y = -1, int width = -1, int height = -1)
{
    std::cout << "Title : " << title << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "Width : " << width << std::endl;
    std::cout << "Height : " << height << std::endl;
}
int main()
{
    /*
    Not all arguments are necessary. If you specify arguments,
    they should be specified from right to left.
    */
    CreateWindow("Notepad", 100, 200);
    return 0;
}
