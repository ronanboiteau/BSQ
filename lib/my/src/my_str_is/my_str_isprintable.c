/*
** my_str_isprintable.c for my_str_isprintable in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:17:26 2015 Ronan Boiteau
** Last update Thu Dec 17 23:14:20 2015 Ronan Boiteau
*/

#include "my.h"

int		my_str_isprintable(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 32 && str[idx] <= 126))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
