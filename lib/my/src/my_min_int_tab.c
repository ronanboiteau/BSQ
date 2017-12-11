#include "my.h"

int		my_min_int_tab(const int *tab, const uint size)
{
  uint		idx;
  int		lowest;

  idx = 0;
  lowest = tab[idx];
  while (idx < size)
    {
      if (tab[idx] > lowest)
	lowest = tab[idx];
      idx += 1;
    }
  return (lowest);
}
