#include "my.h"

void		my_sort_int_tab(int *tab, int size)
{
  uint		idx;
  int		sorted;

  sorted = FALSE;
  while (!sorted)
    {
      sorted = TRUE;
      idx = 0;
      while (tab[idx + 1])
	{
	  if (tab[idx] > tab[idx + 1])
	    {
	      my_swap(&tab[idx], &tab[idx + 1]);
	      sorted = FALSE;
	    }
	  idx += 1;
	}
      my_max_int_tab(tab, size);
      idx += 1;
    }
  return ;
}
