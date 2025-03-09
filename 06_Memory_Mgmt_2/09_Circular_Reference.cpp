#include <iostream>
#include <memory>

class Employee; //forward declaration

class Project
{
public:
    Employee* emp;
    Project()
    {
        std::cout << "Project()" << std::endl;
    }
    ~Project()
    {
        std::cout << "~Project()" << std::endl;
    }
    void SetEmployee(Employee* emp)
    {
        this->emp = emp;
    }
};

class Employee
{
public:
    Project* prj;
    Employee()
    {
        std::cout << "Employee()" << std::endl;
    }
    ~Employee()
    {
        std::cout << "~Employee()" << std::endl;
    }
    void SetProject(Project* prj)
    {
        this->prj = prj;
    }
};

int main()
{
    Project* prj = new Project;
    Employee* emp = new Employee;

    prj->SetEmployee(emp);
    emp->SetProject(prj);

    delete prj;
    delete emp;
}