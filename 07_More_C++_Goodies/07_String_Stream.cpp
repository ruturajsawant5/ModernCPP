#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int a{3}, b{5};
    int sum = a + b;
    std::cout << a << " + " << b << " = " << sum << std::endl;
    //std::string res = a + " + " + b;

    std::stringstream ss; // input and output
    ss << a << " + " << b << " = " << sum << std::endl;
    std::cout << ss.str();

    ss.str(""); //clear out

    std::ostringstream os; //output
    os << a << " + " << b << " = " << sum << std::endl;
    std::cout << os.str();

    std::string data{"10 20 30 40 50"};
    std::istringstream is; //input
    int q;
    is.str(data);
    while(!is.fail())
    {
        is >> q;
        std::cout << q << " ";
    }
    //last element twice
    //10 20 30 40 50 50

    std::cout << std::endl;

    std::string data2{"50 20 30 40 50"};
    std::istringstream is2; //input
    is2.str(data2);
    while(is2 >> q)
    {
        std::cout << q << " ";
    }

    std::cout << std::endl;

    //int to string
    std::cout << std::to_string(100) << std::endl;
    int num = std::stoi("500");
    std::cout << num << std::endl;

    return 0;
}