#include "my.h"

int		match(const char *str1, const char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (0);
  else if ((*str1 == '\0') && (*str2 == '\0'))
    return (1);
  else if (*str1 == *str2)
    return (match(str1 + 1, str2 + 1));
  else if ((*str1 == '*') || (*str2 == '*'))
    return (match(str1, str2 + 1) || match(str1 + 1, str2));
  else
    return (0);
}
