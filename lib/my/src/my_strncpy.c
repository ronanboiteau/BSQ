#include "my.h"

char		*my_strncpy(char *dest, const char *src, uint nbr)
{
  uint		idx;

  idx = 0;
  while (src[idx] != '\0' && idx < nbr)
    {
      dest[idx] = src[idx];
      idx += 1;
    }
  dest[idx] = '\0';
  return (dest);
}
