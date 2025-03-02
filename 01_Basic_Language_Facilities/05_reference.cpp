#include <iostream>

int
main ()
{
  // Referent
  int x = 10;

  // Reference
  int &ref = x;
  int y = 20;
  ref = y;

  std::cout << "x:" << x << std::endl;
  std::cout << "ref:" << ref << std::endl;

  return 0;
}
