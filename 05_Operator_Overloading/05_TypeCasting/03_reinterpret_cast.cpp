#include <iostream>

int
main ()
{
  int a = 5;

  // CTE
  // char* c = static_cast<char*>(&a);

  // WORKS
  char *c = reinterpret_cast<char *> (&a);
  std::cout << c << std::endl;

  const int x = 1;
  int *p = (int *)&x; // WORKS const qualifier removed
  *p = 200;

  // error: ‘reinterpret_cast’ from type ‘const int*’ to type ‘int*’ casts away
  // qualifiers constness maintained int *p2 = reinterpret_cast<int*>(&x);

  return 0;
}