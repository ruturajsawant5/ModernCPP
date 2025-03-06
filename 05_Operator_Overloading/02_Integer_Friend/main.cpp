#include "Integer.h"
#include <iostream>

int
main ()
{
  Integer a (5);
  Integer b (10);

  Integer c = a + b;
  std::cout << a.GetValue () << " + " << b.GetValue () << " = "
            << c.GetValue () << std::endl;

  std::cout << "Before ++c : " << c.GetValue () << std::endl;
  ++c;
  std::cout << "After  ++c : " << c.GetValue () << std::endl;

  std::cout << "Before c++ : " << c.GetValue () << std::endl;
  Integer d = c++;
  std::cout << "After  c++ c: " << c.GetValue () << std::endl;
  std::cout << "After  c++ d: " << d.GetValue () << std::endl;

  std::cout << "c == d -> " << (c == d) << std::endl;
  d++;
  std::cout << "c == d -> " << (c == d) << std::endl;

  Integer e = d + 5;
  std::cout << "e = " << e.GetValue () << std::endl;

  Integer f = 5 + e;
  std::cout << "f = " << f.GetValue () << std::endl;

  std::cout << a << " " << b << " " << c << std::endl;

  Integer g;
  std::cin >> g;
  std::cout << g << std::endl;

  g ();

  return 0;
}