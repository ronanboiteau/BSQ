#include "my.h"

int		my_str_islower(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 'a' && str[idx] <= 'z'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
