#include <iostream>
#include <cstring>

char* CombineName(const char* firstname, const char* lastname)
{
    char* fullname = new char[strlen(firstname) + strlen(lastname) + 1 + 1];
    strncpy(fullname, firstname, strlen(firstname));
    strncat(fullname, " ", 1);
    strncat(fullname, lastname, strlen(lastname));
    return fullname;

}

int main()
{
    char firstname[20];
    char lastname[20];

    std::cout << "Enter First Name : ";
    std::cin >> firstname;

    std::cout << "Enter Last Name : ";
    std::cin >> lastname;

    char* fullname = CombineName(firstname, lastname);
    std::cout << "Full Name = " << fullname << std::endl;
    //delete fullname; ERROR PRONE
    delete[] fullname;
    return 0;
}
