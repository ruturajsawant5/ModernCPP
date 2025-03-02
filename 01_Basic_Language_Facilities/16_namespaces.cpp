#include <iostream>

namespace Avg
{
float
Calculate (float x, float y)
{
  return (x + y) / 2;
}
} // namespace Avg

namespace Basic
{
float
Calculate (float x, float y)
{
  return x + y;
}
} // namespace Basic

namespace Sort
{
void
Quicksort ()
{
}

void
Insertionsort ()
{
}

void
Mergesort ()
{
}

namespace Comparision
{
void
Less ()
{
}

void
Greater ()
{
}
} // namespace Comparision
} // namespace Sort

namespace
{
void
InternalFunction ()
{
}
} // namespace

int
main ()
{
  // Avoid opening a namespace at a global scope

  InternalFunction ();
  using namespace Sort::Comparision;
  Sort::Comparision::Less ();
  return 0;
}
