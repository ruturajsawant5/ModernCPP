#include <iostream>

void
TwoD ()
{
  int *p1 = new int[3];
  int *p2 = new int[3];

  int **pData = new int *[2];
  pData[0] = p1;
  pData[1] = p2;

  pData[0][1] = 2;

  delete[] p1; // delete pData[0]
  delete[] p2;

  delete[] pData;
}
int
main ()
{
  int data[2][3] = { 1, 2, 3, 4, 5, 6 }; // 1,2,3,4,5,6
                                         // data[0][1]
  TwoD ();
  return 0;
}
