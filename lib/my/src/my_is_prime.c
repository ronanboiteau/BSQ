#include "my.h"

int		my_is_prime(const int nbr)
{
  int		idx;

  if (nbr <= 1)
    return (FALSE);
  idx = 2;
  while (idx < nbr)
    {
      if (nbr % idx == 0)
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
