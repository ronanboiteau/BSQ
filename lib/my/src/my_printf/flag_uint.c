#include "my.h"
#include "printf_flags.h"
#include "printf_puts.h"

uint	_convert_binary(int fd, uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, uint), "01");
  return (printed);
}

uint	_convert_decimal(int fd, uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, uint), "0123456789");
  return (printed);
}

uint	_convert_hex_lowcase(int fd, uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, uint), "0123456789abcdef");
  return (printed);
}

uint	_convert_hex_upcase(int fd, uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, uint), "0123456789ABCDEF");
  return (printed);
}

uint	_convert_octal(int fd, uint printed, va_list ap)
{
  printed += my_putnbr_base_fd(fd, va_arg(ap, uint), "01234567");
  return (printed);
}
