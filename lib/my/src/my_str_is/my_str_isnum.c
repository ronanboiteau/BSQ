/*
** my_str_isnum.c for my_str_isnum in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:01:08 2015 Ronan Boiteau
** Last update Thu Dec 17 23:13:47 2015 Ronan Boiteau
*/

#include "my.h"

int		my_str_isnum(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= '0' && str[idx] <= '9'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
