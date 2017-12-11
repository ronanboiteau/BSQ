#include "my.h"

uint		my_putstr_fd(int fd, const char *str)
{
  if (str == NULL)
    {
      write(fd, "(null)", my_strlen("(null)"));
      return (my_strlen("(null)"));
    }
  write(fd, str, my_strlen(str));
  return (my_strlen(str));
}

uint		my_putstr(const char *str)
{
  return (my_putstr_fd(STDOUT, str));
}
