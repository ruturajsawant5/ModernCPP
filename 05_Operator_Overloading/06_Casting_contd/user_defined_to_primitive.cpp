#include "Integer.h"
#include <iostream>

void
Print (Integer x)
{
  std::cout << x << std::endl;
}

int
main ()
{
  Integer a1{ 5 };

  int x = a1;
  // disable implicit conversion by explicit keyword

  // explicit
  int y = static_cast<int> (a1);

  return 0;
}