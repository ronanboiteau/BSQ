#include "my.h"

int		my_strcmp(const char *str1, const char *str2)
{
  uint		idx;

  idx = 0;
  while (str1[idx] != '\0' && str2[idx] != '\0')
    {
      if (str1[idx] != str2[idx])
	return (str1[idx] - str2[idx]);
      idx += 1;
    }
  return (0);
}
