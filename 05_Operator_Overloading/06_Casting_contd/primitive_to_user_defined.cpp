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
  /*
  Integer::Integer(int value)
  */

  Integer a2 = 5;
  /*
  Integer::Integer(int value)
  */

  Print (5);
  /*
  Integer::Integer(int value)
  */

  a2 = 7;
  /*
  Integer::Integer(int value)
  */

  return 0;
}