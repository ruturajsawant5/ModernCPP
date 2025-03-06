#include "Integer.h"
#include <iostream>

void
CreateInteger ()
{
  Integer *p = new Integer (5);
  std::cout << p->GetValue () << std::endl;
  std::cout << *p << std::endl;
  std::cout << "No Call to Destructor Memory Leak" << std::endl;
}

class IntPtr
{
  Integer *ptr;

public:
  IntPtr (Integer *p) : ptr (p)
  {
    std::cout << "IntPtr(Integer *p)" << std::endl;
  }
  ~IntPtr ()
  {
    std::cout << "~IntPtr()" << std::endl;
    delete ptr;
  }
  // overload -> and *
  Integer *
  operator->()
  {
    return ptr;
  }
  Integer &
  operator* ()
  {
    return *ptr;
  }
};

void
CreateIntegerSmart ()
{
  IntPtr p = new Integer (5);
  std::cout << p->GetValue () << std::endl;
  std::cout << *p << std::endl;
}

int
main ()
{
  CreateInteger ();
  CreateIntegerSmart ();
  return 0;
}