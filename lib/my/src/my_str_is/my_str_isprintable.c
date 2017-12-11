#include "my.h"

int		my_str_isprintable(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 32 && str[idx] <= 126))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
