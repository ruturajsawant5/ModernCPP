#include <stdio.h>
#include <stdlib.h>

void
Malloc ()
{
  // int *p = (int*)calloc(5, sizeof(int));
  int *p = (int *)malloc (5 * sizeof (int));
  if (p == NULL)
    {
      printf ("Failed to allocate memory\n");
      return;
    }
  *p = 5;
  printf ("%d", *p);
  // free(p);
  p = NULL;
  // free(p);
}

int
main ()
{
  Malloc ();
  return 0;
}
