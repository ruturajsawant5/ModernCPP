#include <iostream>

void Add (int a, int b, int &result); // Add two numbers and return the result
                                      // through a reference parameter
void Factorial (int a, int &result);  // Find factorial of a number and return
                                      // that through a reference parameter
void Swap (int &a, int &b); // Swap two numbers through reference arguments

int
main ()
{
  int a = 10;
  int b = 20;

  int res = 0;

  Add (a, b, res);
  std::cout << "Sum of " << a << " and " << b << " is " << res << std::endl;

  a = 1888;
  b = 7878;
  std::cout << "Before Swap: a = " << a << " b = " << b << std::endl;
  Swap (a, b);
  std::cout << "After Swap: a = " << a << " b = " << b << std::endl;

  int f = 5;
  Factorial (f, res);
  std::cout << "Factorial of " << f << " is " << res << std::endl;

  return 0;
}

void
Add (int a, int b, int &result)
{
  result = a + b;
}

void
Factorial (int a, int &result)
{
  result = 1;
  for (int i = 1; i <= a; i++)
    result *= i;
}
void
Swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
