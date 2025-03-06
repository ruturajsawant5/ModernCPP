#include "Integer.h"
#include <iostream>
#include <memory>

void
ProcessInteger (std::shared_ptr<Integer> obj)
{
  std::cout << *obj << std::endl;
}

void
ProcessInteger2 (std::shared_ptr<Integer> obj)
{
  std::cout << *obj << std::endl;
}

int
main ()
{
  std::shared_ptr<Integer> p (new Integer (50));
  std::cout << *p << std::endl;

  ProcessInteger (p);
  ProcessInteger (p);
  // delete p;
  return 0;
}