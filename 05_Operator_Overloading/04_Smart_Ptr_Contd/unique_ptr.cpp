#include "Integer.h"
#include <iostream>
#include <memory>

void
ProcessInteger (std::unique_ptr<Integer> obj)
{
  std::cout << *obj << std::endl;
}

int
main ()
{
  std::unique_ptr<Integer> p (new Integer (50));
  std::cout << *p << std::endl;

  ProcessInteger (std::move (p));

  // delete p;
  return 0;
}