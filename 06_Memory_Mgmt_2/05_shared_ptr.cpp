#include <iostream>
#include <string>
#include <memory>
#include <utility>

class Project
{
    std::string name;
    //List of emp

public:
    void SetName(std::string name)
    {
        this->name = std::move(name);
    }

    std::string GetName()
    {
        return name;
    }
};

class Employee
{
    std::string name;
    std::shared_ptr<Project> project;

public:
    void SetName(std::string name)
    {
        this->name = std::move(name);
    }

    std::string GetName()
    {
        return name;
    }

    void SetProject(const std::shared_ptr<Project> &project)
    {
        this->project = project;
    }

    std::shared_ptr<Project>& GetProject()
    {
        return project;
    }

    void display() const
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Employer: " << project->GetName() << std::endl;
    }
};

int main()
{
    std::shared_ptr<Project> prj (new Project);
    prj->SetName ("GOOGLE");

    auto *emp = new Employee;
    emp->SetName ("RUTURAJ");
    emp->SetProject (prj);

    auto *emp2 = new Employee;
    emp2->SetName ("NEW RUTURAJ");
    emp2->SetProject (prj);

    emp->display ();
    emp2->display ();

    delete emp;
    delete emp2;

    return 0;
}