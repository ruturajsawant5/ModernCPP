#include "Integer.h"
#include <iostream>

void
Display (Integer *p)
{
  if (!p)
    return;
  std::cout << *p << std::endl;
}

Integer *
GetPointer (int value)
{
  Integer *p = new Integer (value);
  return p;
}

void
Operate (int value)
{
  Integer *p = GetPointer (value);

  if (!p)
    {
      p = new Integer ();
    }

  Display (p);
  p->SetValue (100);
  Display (p);

  delete p; // we forget to free p
  p = nullptr;

  p = new Integer ();

  *p = __LINE__;
  Display (p);

  // FORGOT TO DELETE P
  delete p;
}

int
main ()
{
  Operate (500);
  return 0;
}
