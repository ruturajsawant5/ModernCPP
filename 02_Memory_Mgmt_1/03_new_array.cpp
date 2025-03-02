#include <iostream>
#include <string.h>

void
NewArrays ()
{
  int *p = new int[5];
  for (int i = 0; i < 5; ++i)
    {
      p[i] = i;
    }
  delete[] p;
}
void
Strings ()
{
  char *p = new char[4];
  // strcpy_s(p, 4, "C++");
  strcpy (p, "C++");
  std::cout << p << std::endl;
  delete[] p;
}

int
main ()
{
  NewArrays ();
  Strings ();
  return 0;
}
