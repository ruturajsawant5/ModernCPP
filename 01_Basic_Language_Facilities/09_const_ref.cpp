#include <iostream>

int
main ()
{
  // Try to modify x1 & x2 and see the compilation output
  int x = 5;
  const int MAX = 12;

  int &ref_x1 = x;
  const int &ref_x2 = x;

  ref_x1 = 5;
  // ref_x2 = 10; //error: assignment of read-only reference ‘ref_x2’

  // Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
  const int *ptr1 = &x;
  int *const ptr2 = &x;
  const int *const ptr3 = &x;

  // Find which declarations are valid. If invalid, correct the declaration
  const int *ptr5 = &MAX;
  // int *ptr4 = &MAX ; // error: invalid conversion from ‘const int*’ to
  // ‘int*’

  const int &r1 = ref_x1;
  // int &r2 = ref_x2 ; //error: invalid conversion from ‘const int*’ to ‘int*’

  // int *&p_ref1 = ptr1 ; //error: binding reference of type ‘int*&’ to ‘const
  // int*’ discards qualifiers const int*&p_ref2 = ptr2 ; //error: binding
  // reference of type ‘int*&’ to ‘const int*’ discards qualifiers

  return 0;
}
