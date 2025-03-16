#include <iostream>
#include <fstream>
int main()
{
    int x = 5;

    auto f = [x]() {
        std::cout << x << std::endl;
    };
    f();

    //Generalized Capture
    auto f2 = [y = x]() {
        std::cout << y << std::endl;
    };
    f2();

    std::ofstream out {"file1.txt", std::ios::out | std::ios::app};
    auto f3 = [&out] (int x) {
        out << x << std::endl;
    };
    f3(55);
    //still can acccess out
    out << "ABRA" << std::endl;
    out.close();

    std::ofstream out2 {"file1.txt", std::ios::out | std::ios::app};
    auto f4 = [out = std::move(out2)] (int x) mutable{
        out << x << std::endl;
    };
    f4(55);
   // out2 << "NOT AN ABRA" << std::endl;


    return 0;
}