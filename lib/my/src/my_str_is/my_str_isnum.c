#include "my.h"

int		my_str_isnum(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= '0' && str[idx] <= '9'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
