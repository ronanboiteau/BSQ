#include "my.h"

int		my_char_isprintable(const char letter)
{
  if (!(letter >= 32 && letter <= 126))
    return (FALSE);
  return (TRUE);
}
