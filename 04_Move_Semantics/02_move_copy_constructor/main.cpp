#include "Integer.h"
#include <iostream>

Integer
Add (const Integer &a, const Integer &b)
{
  Integer temp;
  temp.SetValue (a.GetValue () + b.GetValue ());
  return temp;
}
int
main ()
{
  Integer a (1), b (3);
  // a.SetValue (Add (a, b).GetValue ());
  Integer c = Add (a, b);
  return 0;
}
// Copy Elision
// g++ -fno-elide-constructors Integer.cpp main.cpp