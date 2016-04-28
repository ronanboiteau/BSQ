/*
** my_str_isupper.c for my_str_isupper in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 18:09:47 2015 Ronan Boiteau
** Last update Thu Dec 17 23:14:04 2015 Ronan Boiteau
*/

#include "my.h"

int		my_str_isupper(const char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}
