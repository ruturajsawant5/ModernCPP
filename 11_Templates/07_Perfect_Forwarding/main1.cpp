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
    Employee( std::string &name,  Integer &id) :
        m_Name{ name },
        m_Id{ id } {
        std::cout << "Employee(std::string &name, Integer &id)" << std::endl;
    }

    // Constructor 3: rvalue reference for name, int for id
    Employee(std::string &&name, Integer &id) :
        m_Name{ std::move(name) },
        m_Id{ id } { // Implicit conversion from int to Integer
        std::cout << "Employee(std::string &&name, int& id)" << std::endl;
    }

    // Constructor 4: const lvalue reference for name, int for id
    Employee(std::string &name, Integer&& id) :
        m_Name{ name },
        m_Id{ std::move(id) } { // Implicit conversion from int to Integer
        std::cout << "Employee(const std::string &name, int&& id)" << std::endl;
    }

};

int main()
{
     std::string name{"Ruturaj"};
     Integer id{100};
     Integer id2{100};

    std::cout << "----------------CASE1x----------------" << std::endl;
    Employee emp1{ "Ruturaj", 100 };
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE2----------------" << std::endl;
    Employee emp2{name, 100};
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE3----------------" << std::endl;
    Employee emp3{ "Ruturaj", id };
    //Employee emp3{ "Ruturaj", std::move(id) };
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "----------------CASE4----------------" << std::endl;
    Employee emp4{ name, id2 };
    //Employee emp4{ name, std::move(id2) };
    std::cout << "-------------------------------------" << std::endl;

    /*
    ----------------CASE1----------------
    Integer(int)
    Integer(int&&)
    Employee(std::string &&name, Integer &&id)
    ~Integer()
    -------------------------------------
    ----------------CASE2----------------
    Integer(int)
    Integer(int&&)
    Employee(const std::string &name, int&& id)
    ~Integer()
    -------------------------------------
    ----------------CASE3----------------
    Integer(const Integer&)
    Employee(std::string &&name, int& id)
    -------------------------------------
    ----------------CASE4----------------
    Integer(const Integer&)
    Employee(const std::string &name, Integer &id)
    -------------------------------------
    */



    return 0;
}