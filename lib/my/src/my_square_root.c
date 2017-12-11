#include "my.h"

int		my_square_root(const int nbr)
{
  ll		tmp;
  int		result;

  result = 0;
  if (nbr >= 0)
    {
      while ((tmp = (ll)result * (ll)result) != nbr && result <= nbr)
	result += 1;
    }
  else
    return (0);
  if (result == nbr + 1)
    return (0);
  else
    return (result);
}
