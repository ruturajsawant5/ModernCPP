#include <iostream>
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
  SetName (std::string name)
  {
    this->name = name;
  }
};

class Employee
{
  std::string name;
  Project *prj;

public:
  std::string
  GetName () const
  {
    return name;
  }

  void
  SetName (std::string name)
  {
    this->name = name;
  }

  Project *
  GetProject () const
  {
    return prj;
  }

  void
  SetProject (Project *prj)
  {
    this->prj = prj;
  }

  void
  display ()
  {
    std::cout << "EMP NAME: " << name << std::endl;
    std::cout << "PRJ NAME: " << prj->GetName () << std::endl;
  }
};

int
main ()
{
  Project *prj = new Project;
  prj->SetName ("GOOGLE");

  Employee *emp = new Employee;
  emp->SetName ("RUTURAJ");
  emp->SetProject (prj);

  Employee *emp2 = new Employee;
  emp2->SetName ("NEW RUTURAJ");
  emp2->SetProject (prj);

  emp->display ();
  emp2->display ();

  delete prj;
  delete emp;
  delete emp2;

  return 0;
}
