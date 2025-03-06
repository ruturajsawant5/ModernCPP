#include <iostream>

int
main ()
{
  int a = 5, b = 2;

  // Safer than c style casts
  float i = static_cast<float> (a) / b;
  std::cout << i << std::endl;

  // CTE
  // char* c = &a;

  char *c = (char *)&a; // allowed but its not correct

  // CTE error: invalid ‘static_cast’ from type ‘int*’ to type ‘char*’
  // char* d = static_cast<char*>(&a);

  return 0;
}