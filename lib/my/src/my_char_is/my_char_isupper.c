#include "my.h"

int		my_char_isupper(const char letter)
{
  if (!(letter >= 'A' && letter <= 'Z'))
    return (FALSE);
  return (TRUE);
}
