#include <iostream>
#include <string>
#include <sstream>
using namespace std::string_literals;

class Distance
{
    long double d = 0.0;

public:
    Distance() : d(0.0) {}
    Distance(long double _d): d(_d) {}
    long double GetKM() const
    {
        return d;
    }
};

Distance operator""_mi(long double val)
{
    return Distance(val*1.6);
}

Distance operator""_meters(unsigned long long val)
{
    return Distance(val/1000.0);
}

int main()
{
    Distance d1{23.0_mi};
    std::cout << d1.GetKM() << std::endl;

    Distance d2{223455_meters};
    std::cout << d2.GetKM() << std::endl;
}