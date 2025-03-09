#include <iostream>
#include <memory>
#include <string>

class Project
{
  std::string name;
  // List of employee not implemented

public:
  std::string
  GetName () const
  {
    return name;
  }

  void
  SetName (const std::string& name)
  {
    this->name = name;
  }
};

class Employee
{
  std::string name;
  // Project* prj;
  std::unique_ptr<Project> prj;

public:
  std::string
  GetName () const
  {
    return name;
  }

  void
  SetName (const std::string& name)
  {
    this->name = name;
  }

  std::unique_ptr<Project> &
  GetProject ()
  {
    return prj;
  }

  void
  SetProject (std::unique_ptr<Project> &prj)
  {
    this->prj = std::move (prj);
  }

  void
  display () const
  {
    std::cout << "EMP NAME: " << name << std::endl;
    std::cout << "PRJ NAME: " << prj->GetName () << std::endl;
  }
};

int
main ()
{
  std::unique_ptr<Project> prj (new Project);
  prj->SetName ("GOOGLE");

  Employee *emp = new Employee;
  emp->SetName ("RUTURAJ");
  emp->SetProject (prj);

  Employee *emp2 = new Employee;
  emp2->SetName ("NEW RUTURAJ");
  emp2->SetProject (prj); // CRASHES HERE
                          // ownership is moved from prj to employee object so
                          // prj contains ...

  emp->display ();
  emp2->display ();

  delete emp;
  delete emp2;

  return 0;
}
