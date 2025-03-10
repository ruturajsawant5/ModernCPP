#include <iostream>
#include <string>

std::string ToUpper(const std::string &str)
{
    std::string res = str;
    for(int i = 0; i < str.length(); i++)
    {
        res[i] = toupper(res[i]);
    }
    return res;
}

std::string ToLower(const std::string &str)
{
    std::string res = str;
    for(int i = 0; i < str.length(); i++)
    {
        res[i] = tolower(res[i]);
    }
    return res;
}

int main()
{
    std::string name = "hello";
    std::cout << name << std::endl;
    std::string upperString = ToUpper(name);
    std::cout << upperString << std::endl;
    std::string lowerString = ToLower(name);
    std::cout << lowerString << std::endl;

}