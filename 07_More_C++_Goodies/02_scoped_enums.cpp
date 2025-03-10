#include <iostream>

//enum COLOR {Red, Green, Blue};
//enum TRAFFIC_LIGHTS {Red, Green, Blue}; //REDEF ERROR

enum class COLOR {Red, Green, Blue};
enum class TRAFFIC_LIGHTS {Red, Green, Blue};

//ASCII of r will be Red
enum class TRAFFIC_LIGHTS2 : char {Red='r', Green, Blue};

void FillColor(COLOR c)
{
    //std::cout << c << std::endl; no implicit conversion
    std::cout << static_cast<int> (c) << std::endl;
}

void FillColor2(TRAFFIC_LIGHTS c)
{
    //std::cout << c << std::endl;
    std::cout << static_cast<int> (c) << std::endl;
}

int main()
{
    FillColor(COLOR::Blue);
    FillColor2(TRAFFIC_LIGHTS::Red);
    return 0;
}