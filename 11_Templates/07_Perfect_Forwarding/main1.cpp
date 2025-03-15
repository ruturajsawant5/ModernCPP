#include "Integer.h"
#include <iostream>
#include <string>

class Employee {
    std::string m_Name;
    Integer m_Id;
public:
    // Constructor 1: rvalue reference for name, rvalue reference for Integer
    Employee(std::string &&name, Integer &&id) :
        m_Name{ std::move(name) },
        m_Id{ std::move(id) } {
        std::cout << "Employee(std::string &&name, Integer &&id)" << std::endl;
    }

    // Constructor 2: const lvalue reference for name, const lvalue reference for Integer
    Employee(const std::string &name, const Integer &id) :
        m_Name{ name },
        m_Id{ id } {
        std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl;
    }

    // Constructor 3: rvalue reference for name, int for id
    Employee(std::string &&name, int id) :
        m_Name{ std::move(name) },
        m_Id{ id } { // Implicit conversion from int to Integer
        std::cout << "Employee(std::string &&name, int id)" << std::endl;
    }

    // Constructor 4: const lvalue reference for name, int for id
    Employee(const std::string &name, int id) :
        m_Name{ name },
        m_Id{ id } { // Implicit conversion from int to Integer
        std::cout << "Employee(const std::string &name, int id)" << std::endl;
    }

};

int main()
{
    const std::string name{"Ruturaj"};
    const Integer id{100};
    std::cout << "-------------------------------------" << std::endl;
    Employee emp1{ "Ruturaj", 100 };
    std::cout << "-------------------------------------" << std::endl;
    Employee emp2{name, 100};
    std::cout << "-------------------------------------" << std::endl;
    Employee emp3{ "Ruturaj", id };
    std::cout << "-------------------------------------" << std::endl;
    Employee emp4{ name, id };
    std::cout << "-------------------------------------" << std::endl;

    /*
    -------------------------------------
    Integer(int)
    Employee(std::string &&name, int id)
    -------------------------------------
    Integer(int)
    Employee(const std::string &name, int id)
    -------------------------------------
    Integer(const Integer&)---------------------------move not getting called
    Employee(const std::string &name, const Integer &id)
    -------------------------------------
    Integer(const Integer&)
    Employee(const std::string &name, const Integer &id)
    -------------------------------------
    */

    return 0;
}