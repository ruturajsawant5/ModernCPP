#include <iostream>
#include <functional>

int Square(int x)
{
    return x * x;
}

void Print(const char* p)
{
    std::cout << *p << std::endl;
}

int Substract(int x, int y)
{
    return x - y;
}

int Accumulate(int x, int y, int z)
{
    return x + y + z;
}

int Operation(int x, int y, std::function<int(int, int)> callback)
{
    return callback(x, y);
}

struct GreaterThan {
    int operator()(int x, int y) {
        return x > y;
    }
};

int main()
{
    auto f1 = std::bind(Square, 3);
    std::cout << f1() << std::endl;

    const char x = 'a';
    auto f2 = std::bind(Print, std::placeholders::_1);
    f2(&x);

    std::function<int(int, int)> f3 = std::bind(Substract, std::placeholders::_1, std::placeholders::_2);
    std::cout << f3( 5, 10) << std::endl;

    std::function<int(int, int)> f4 = std::bind(Substract, std::placeholders::_2, std::placeholders::_1);
    std::cout << f4( 5, 10) << std::endl;

    std::function<int(int)> f5 = std::bind(Substract, std::placeholders::_1, 100);
    std::cout << f5( 5 ) << std::endl;

    // Operation(5, 10, Accumulate);
    auto acc = std::bind(Accumulate, std::placeholders::_1, std::placeholders::_2, 0);
    std::cout << Operation(115, 10, acc) << std::endl;

    //CAN DO SAME WITH LAMBDA FUNCTION
    auto g1 = [] (int x) {
        return Substract(x, 5);
    };
    g1(1);

    auto g2 = [] (int x, int y) {
        return GreaterThan{}(y, x);
    };
    g2(5, 10);

    //Forward References
    //bind auto forward it
    //explicit std::forward for ...

    auto h1 = [] (auto &&x) {
        return Substract(std::forward<decltype(x)>(x), 5);
    };

    //Above is simplified in C++ 20
    //cl /EHsc 02_bind.cpp /std:c++20
    auto h2 = []<typename T>(T&&x, T&&y) {
        return GreaterThan{}(std::forward<T>(x), std::forward<T>(y));
    };

    return 0;
}