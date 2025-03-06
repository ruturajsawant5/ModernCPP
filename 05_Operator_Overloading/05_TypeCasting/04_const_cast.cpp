#include <iostream>

int
main ()
{
  int a = 5;

  const int x = 1;
  int *p = (int *)&x; // WORKS const qualifier removed
  *p = 200;
  std::cout << *p << std::endl;

  // error: ‘reinterpret_cast’ from type ‘const int*’ to type ‘int*’ casts away
  // qualifiers constness maintained int *p2 = reinterpret_cast<int*>(&x);

  int *p2 = const_cast<int *> (&x);
  *p2 = 400;
  std::cout << *p2 << std::endl;

  return 0;
}