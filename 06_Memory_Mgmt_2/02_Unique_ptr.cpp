#include "Integer.h"
#include <iostream>
#include <memory>

void
Display (const Integer *p)
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
Store (const std::unique_ptr<Integer>& p)
{
  std::cout << "Saving to File" << *p << std::endl;
}

void
Store2 (const std::unique_ptr<Integer> &p)
{
  std::cout << "Saving to File" << *p << std::endl;
}
void
Operate (const int& value)
{
  // Integer* p = GetPointer(value);
  std::unique_ptr<Integer> p (
      GetPointer (value)); // asterisk not needed
                           // explicit constructor so no =

  if (!p)
  {
    // p = new Integer();
    p.reset (new Integer ());
  }

  // Display(p);
  Display (p.get ());
  p->SetValue (100); // -> operator is overloaded
  Display (p.get ());

  // delete p; //NOT NEEDED
  p = nullptr; // THIS WILL FREE p

  p.reset (new Integer ());

  *p = __LINE__;
  Display (p.get ());
  // Store(p); //error: use of deleted function ‘std::unique_ptr<_Tp,
  // _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Integer;
  // _Dp = std::default_delete<Integer>] Store(std::move(p)); shout not use p
  // NOiW Display(p.get());

  // pass by reference so it is fine
  Store2 (p);
  Display (p.get ());

   // delete p;
}

int
main ()
{
  Operate (500);
  return 0;
}
