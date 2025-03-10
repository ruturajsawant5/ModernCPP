#include <iostream>
#include <string>


int main()
{
    //create
    std::string s1;
    s1 = "Hi";

    std::string s2 = "Hello";

    //access
    s2[0] = 'P';
    std::cout << s2 << std::endl;
    std::cout << s2[1] << std::endl;

    std::cout << "Enter One word : ";
    std::cin >> s1; //Stop at ' '

    std::cout << "Enter Line : ";
    // Clean the input buffer by ignoring the remaining characters, including the newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, s1);
    std::cout << s1 << std::endl;

    //length
    std::cout << s1.length() << std::endl;

    //concat
    s1 = s1 + s2;
    std::cout << s1 << std::endl;
    s1 += s2;
    std::cout << s1 << std::endl;

    s1.insert(6, "ABRA");
    std::cout << s1 << std::endl;

    //comparison
    if(s1 < s2)
        std::cout << "s1 < s2" << std::endl;
    //if(s1 <= s2)
    // >
    // >=
    // ==
    // !=

    //Remove
    std::cout << s1 << std::endl;
    s1.erase(); //clear string
    s1.clear();

    std::cout << s2 << std::endl;
    s2.erase(0, 5); //offset count
    std::cout << s2 << std::endl;

    //search
    s1 = "Hello World ABC def ghi World tyuaddf World";
    auto pos = s1.find("World", 0);
    if(pos != std::string::npos)
        std::cout << "Position = " << pos << std::endl;
    auto pos2 = s1.find("NOT A STRING", 0);
    if(pos2 != std::string::npos) //-1
        std::cout << "Position = " << pos2 << std::endl;

    char* s = s1.c_str();

    //Literals
    unsigned int value = 100u;
    using namespace std::string_literals;
    std::string n2 = "Ruturaj Sawant"s;
    auto n3 = "Ruturaj Sawant"s;



    return 0;
}