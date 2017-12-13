#ifndef MY_H_
# define MY_H_

# include "my_macro.h"
# include "my_typedef.h"
# include <unistd.h>
# include <stdlib.h>

int	match(const char *str1, const char *str2);
int	my_char_isalpha(const char letter);
int	my_char_islower(const char letter);
int	my_char_isnum(const char letter);
int	my_char_isprintable(const char letter);
int	my_char_isupper(const char letter);
int	my_dprintf(int fd, const char *format, ...);
void	my_exit(int exit_code, const char *format, ...);
int	my_find_prime_sup(int nbr);
void	my_free_2d_tab(char **tab, const uint lines);
int	my_atoi(const char *str);
int	my_is_prime(const int nbr);
int	my_max_int_tab(const int *tab, const uint size);
int	my_min_int_tab(const int *tab, const uint size);
int	my_power(const int nbr, int power);
int	my_printf(const char *format, ...);
char	*my_revstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(const int nbr);
char	*my_strcapitalize(char *str);
int	my_strcmp(const char *str1, const char *str2);
char	*my_strdup(const char *src);
int	my_str_isalpha(const char *str);
int	my_str_islower(const char *str);
int	my_str_isnum(const char *str);
int	my_str_isprintable(const char *str);
int	my_str_isupper(const char *str);
int	my_strlen(const char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, const char *src, int nbr);
int	my_strncmp(const char *str1, const char *str2, uint nbr);
char	*my_strncpy(char *dest, const char *src, uint nbr);
char	*my_strstr(char *str, const char *to_find);
char	*my_strupcase(char *str);
void	my_swap(int *ptr_a, int *ptr_b);
int	nmatch(const char *str1, const char *str2);

#endif /* !MY_H_ */
