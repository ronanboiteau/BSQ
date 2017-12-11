#include "my.h"

int		my_str_isupper(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
