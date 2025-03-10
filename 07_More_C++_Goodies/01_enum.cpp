#include <iostream>

//Not Readable
#define RED 0 //NOT TYPESAFE
// const int RED = 0;

void FillColor(int color)
{
    std::cout << "Color = " << color << std::endl;
    if(color == RED)
    {
        std::cout << "RED" << std::endl;
    }
    else
    {
        std::cout << "NOT A COLOR" << std::endl;
    }
    //...
}

enum COLOR {Red, Green, Yellow};
//enum COLOR2 {Red = 1, Green, Yellow};

void FillColor2(COLOR c)
{
    std::cout << "COLOR = " << c << std::endl;
    if(c == Red)
    {
        std::cout << "RED" << std::endl;
    }
    else
    {
        std::cout << "Not A COLOR " << c << std::endl;
    }
    //..
}

int main()
{
    FillColor(RED);
    FillColor(-1);

    FillColor2(Red);
    //FillColor2(-1); //cannot convert argument 1 from 'int' to 'COLOR'
    FillColor2(static_cast<COLOR>(-1));
    return 0;
}

