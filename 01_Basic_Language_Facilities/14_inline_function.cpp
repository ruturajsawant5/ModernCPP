#include <iostream>

inline int
Square (int x)
{
  return x * x;
}

// #define Square(x) x*x

int
main ()
{
  int val = 5;
  int result = Square (val + 1);
  std::cout << result << std::endl;
  return 0;
}
