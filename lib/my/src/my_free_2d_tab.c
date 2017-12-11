#include "my.h"

void		my_free_2d_tab(char **tab, const uint lines)
{
  uint		idx;

  idx = 0;
  while (idx < lines)
    {
      free(tab[idx]);
      idx += 1;
    }
  free(tab);
  return ;
}
