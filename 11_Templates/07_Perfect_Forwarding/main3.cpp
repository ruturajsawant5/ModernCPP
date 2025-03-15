#include "Integer.h"
#include <iostream>
#include <string>

class Employee {
    std::string m_Name;
    Integer m_Id;
public:
    template<typename T1, typename T2>
    Employee(T1 &&name, T2 &&id) :
        m_Name{ std::forward<T1>(name) },
        m_Id{ std::forward<T2>(id) } {
        std::cout << "Employee" << std::endl;
    }
};

int main()
{

    std::string name{"Ruturaj"};
    Integer id{100};
    Integer id2{100};

    std::cout << "----------------CASE1----------------" << std::endl;
    Employee emp1{ std::string{"Ruturaj"}, Integer{100} };
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE2----------------" << std::endl;
    Employee emp2{name, Integer{100}};
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE3----------------" << std::endl;
    Employee emp3{ std::string{"Ruturaj"}, id };
    //Employee emp3{ std::string{"Ruturaj"}, std::move(id) };
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE4----------------" << std::endl;
    Employee emp4{ name, id2 };
    //Employee emp4{ name, std::move(id2) };
    std::cout << "-------------------------------------" << std::endl;

//FOR BOTH CASES
/*
Integer(int)
Integer(int)
----------------CASE1----------------
Integer(int)
Employee
-------------------------------------
----------------CASE2----------------
Integer(int)
Employee
-------------------------------------
----------------CASE3----------------
Integer(int&&)
Employee
-------------------------------------
----------------CASE4----------------
Integer(int&&)
Employee
-------------------------------------
~Integer()
~Integer()
~Integer()
~Integer()
~Integer()
~Integer()
*/
    return 0;
}
