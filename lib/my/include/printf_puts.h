#ifndef PRINTF_PUTS_H_
# define PRINTF_PUTS_H_

uint	my_putchar(const char letter);
uint	my_putchar_fd(int fd, const char letter);
uint	my_putnbr_base_fd(int fd, uint nbr, const char *base);
uint	my_putnbr_base_ull(int fd, ull nbr, const char *base);
uint	my_putnbr_printf(int fd, int nbr);
uint	my_put_nbr_fd(int fd, int nbr);
uint	my_putstr(const char *str);
uint	my_putstr_fd(int fd, const char *str);
int	my_showstr(int fd, const char *str);

#endif /* !PRINTF_PUTS_H_ */
