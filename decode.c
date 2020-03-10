#include<stdio.h>
#include <stdlib.h>

int
main ()
{
  char a[101];
  scanf ("%s", &a);
  int n = strlen (a);
  if (a[0] == '0')
    {
      printf ("0");
      return 0;
    }
  int b[n + 1], i;
  b[0] = 1;
  for (i = 1; i < n; i++)
    {
      if (a[i] > '0')
	{
	  b[i] = b[i - 1];
	}

      int t = (a[i - 1] - 48) * 10 + (a[i] - 48);
      if (a[i] == '0')
	{
	  if (a[i - 1] == '0' || a[i - 1] > '2')
	    {
	      printf ("0");
	      return 0;
	    }
	  else
	    {
	      if (i == 1)
		b[i] = 1;
	      else
		b[i] = b[i - 2];
	    }
	}
      else
	{
	  if (t == 0)
	    {
	      printf ("0");
	      return 0;
	    }
	  if (t < 10)
	    {
	      b[i] = b[i - 1];
	    }
	  else if (t < 27)
	    {
	      if (i == 1)
		b[i] += b[i - 1];
	      else
		b[i] += b[i - 2];
	    }
	  else
	    b[i] = b[i - 1];
	}
    }
  for (int i = 0; i < n; i++)
    printf ("%d ", b[i]);
}

