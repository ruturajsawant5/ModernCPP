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
    Employee emp5{ "Ruturaj", Integer{500} };
    std::cout << "-------------------------------------" << std::endl;

    /*
    -------------------------------------
    Integer(int)
    Employee(std::string &&name, int id)
    -------------------------------------
    Integer(int)
    Employee(const std::string &name, int id)
    -------------------------------------
    Integer(const Integer&)
    Employee(const std::string &name, const Integer &id)
    -------------------------------------
    Integer(const Integer&)
    Employee(const std::string &name, const Integer &id)
    -------------------------------------
    */

    return 0;
}