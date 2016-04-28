/*
** printf_puts.h for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Dec 17 23:29:01 2015 Ronan Boiteau
** Last update Thu Dec 17 23:35:49 2015 Ronan Boiteau
*/

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
