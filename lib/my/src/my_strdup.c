#include "my.h"

char		*my_strdup(const char *src)
{
  int		lenght;
  int		idx;
  char		*new_str;

  idx = 0;
  lenght = my_strlen(src);
  if ((new_str = malloc(sizeof(*new_str) * lenght + 1)) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  while (src[idx] != '\0')
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}
