#include <iostream>

void
Print (int count, char ch)
{
  for (int i = 0; i < count; ++i)
    {
      std::cout << ch;
    }
  std::cout << std::endl;
}

void
EndMessage ()
{
  std::cout << "End of program" << std::endl;
}

int
main ()
{
  // Register a handler. This handler will be invoked after main returns
  atexit (EndMessage);
  Print (5, '#');
  void (*pfn) (int, char) = Print;
  // One way to invoke function pointer
  (*pfn) (8, '@');
  // Another way to invoke function pointer
  pfn (5, '+');
  std::cout << "end of main" << std::endl;
  return 0;
}
