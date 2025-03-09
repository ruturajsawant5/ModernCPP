#include <iostream>
#include <memory>

class Employee; //forward declaration

class Project
{
public:
    std::weak_ptr<Employee> emp;
    Project()
    {
        std::cout << "Project()" << std::endl;
    }
    ~Project()
    {
        std::cout << "~Project()" << std::endl;
    }
    void SetEmployee(std::shared_ptr<Employee>& emp)
    {
        std::cout << "Project RefCnt:" << this->emp.use_count() << std::endl;
        this->emp = emp;
        std::cout << "Project RefCnt:" << this->emp.use_count() << std::endl;
    }
};

class Employee
{
public:
    std::weak_ptr<Project> prj;
    Employee()
    {
        std::cout << "Employee()" << std::endl;
    }
    ~Employee()
    {
        std::cout << "~Employee()" << std::endl;
    }
    void SetProject(std::shared_ptr<Project>& prj)
    {
        std::cout << "Employee RefCnt:" << this->prj.use_count() << std::endl;
        this->prj = prj;
        std::cout << "Employee RefCnt:" << this->prj.use_count() << std::endl;
    }
};

int main()
{
    std::shared_ptr<Project> prj( new Project);
    std::shared_ptr<Employee> emp(new Employee);

    prj->SetEmployee(emp);
    emp->SetProject(prj);
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Project RefCnt " << prj.use_count() << std::endl;
    std::cout << "Employee RefCnt " << emp.use_count() << std::endl;

    prj = nullptr;

    std::cout << "Destructors not called" << std::endl;

    return 0;
}