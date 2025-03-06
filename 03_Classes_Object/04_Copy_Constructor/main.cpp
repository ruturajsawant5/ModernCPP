#include "Integer.h"
#include <iostream>
#include <memory>

void
Process (Integer val)
{

}
Integer Add(int x, int y)
{
  return Integer(x+y);
}

int
main ()
{
  Integer a (3);
  std::cout << "-----------------" << std::endl;
  Integer b(a);
  std::cout << "-----------------" << std::endl;
  Process (a);
  std::cout << "-----------------" << std::endl;
  Integer c  = Add(4, 6);
  std::cout << "-----------------" << std::endl;
  return 0;
}
