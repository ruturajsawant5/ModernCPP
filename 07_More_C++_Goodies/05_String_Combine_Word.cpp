#include <iostream>
#include <string>

std::string CombineNames(std::string first, std::string last)
{
    std::string fullname = first + " " + last;
    return fullname;
}

int main()
{
    std::string first;
    std::string last;
    std::cin >> first;
    std::cin >> last;
    std::string fullname = CombineNames(first, last);
    std::cout << fullname << std::endl;
    return 0;
}
