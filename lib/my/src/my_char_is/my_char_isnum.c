#include "my.h"

int		my_char_isnum(const char letter)
{
  if (!(letter >= '0' && letter <= '9'))
    return (FALSE);
  return (TRUE);
}
