#include "my.h"

int		my_char_islower(const char letter)
{
  if (!(letter >= 'a' && letter <= 'z'))
    return (FALSE);
  return (TRUE);
}
