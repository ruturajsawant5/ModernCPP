#include <iostream>

void
New ()
{
  int *p = new int (5);
  *p = 6;
  std::cout << *p << std::endl;
  delete p;
  p = nullptr;
}

int
main ()
{
  New ();
  return 0;
}
