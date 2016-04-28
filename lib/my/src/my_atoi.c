/*
** my_atoi.c for my_atoi in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Dec 18 02:12:36 2015 Ronan Boiteau
** Last update Fri Dec 18 02:12:43 2015 Ronan Boiteau
*/

#include "my.h"

static int	_skip_letters(const char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] && str[idx] != '-' && str[idx] != '+' &&
	 (str[idx] < '0' || str[idx] > '9'))
    idx += 1;
  while ((str[idx + 1] && (str[idx + 1] == '-' ||
			     str[idx + 1] == '+'))
	 || str[idx] == '+')
    idx += 1;
  return (idx);
}

static int	_set_reverser(const char *str, int *idx)
{
  if (str[*idx] == '-')
    {
      *idx += 1;
      return (-1);
    }
  return (1);
}

int		my_atoi(const char *str)
{
  ll		result;
  int		reverser;
  int		idx;
  int		lenght;
  int		int_min;
  int		int_max;

  result = 0;
  int_min = -2147483648;
  int_max = 2147483647;
  idx = _skip_letters(str);
  reverser = _set_reverser(str, &idx);
  lenght = idx;
  while (str[lenght] >= '0' && str[lenght] <= '9')
    lenght += 1;
  while (idx < lenght)
    {
      result = result + (ll)((str[idx] - '0') *
			     my_power(10, lenght - idx - 1));
      if (result < int_min || result - 1 > int_max)
	return (0);
      idx += 1;
    }
  result *= reverser;
  return ((int)result);
}
