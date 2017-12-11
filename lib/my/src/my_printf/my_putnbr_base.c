#include "my.h"
#include "printf_puts.h"

uint		my_putnbr_base_fd(int fd, uint nbr, const char *base)
{
  uint	base_int;
  uint	printed;

  printed = 0;
  base_int = 0;
  while (base[base_int] != '\0')
    base_int = base_int + 1;
  if (base_int < 2)
    return (0);
  if (nbr >= base_int)
    printed += my_putnbr_base_fd(fd, nbr / base_int, base);
  printed += my_putchar_fd(fd, base[nbr % base_int]);
  return (printed);
}

uint	my_putnbr_base_ull(int fd, ull nbr, const char *base)
{
  uint	base_int;
  uint	printed;

  printed = 0;
  base_int = 0;
  while (base[base_int] != '\0')
    base_int = base_int + 1;
  if (base_int < 2)
    return (0);
  if (nbr >= base_int)
    printed += my_putnbr_base_ull(fd, nbr / base_int, base);
  printed += my_putchar_fd(fd, base[nbr % base_int]);
  return (printed);
}
