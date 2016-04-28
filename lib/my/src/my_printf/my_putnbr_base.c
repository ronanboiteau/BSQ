/*
** my_putnbr_base.c for my_putnbr_base in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct 19 00:17:18 2015 Ronan Boiteau
** Last update Thu Dec 17 23:34:58 2015 Ronan Boiteau
*/

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
