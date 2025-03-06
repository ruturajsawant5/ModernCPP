#include <iostream>

int
main ()
{
  int a = 5, b = 2;

  float f = a;
  std::cout << f << std::endl;

  float g = a / b;
  std::cout << g << std::endl;

  // c style casts are discouraged in c++
  float i = (float)a / b;
  std::cout << i << std::endl;

  return 0;
}