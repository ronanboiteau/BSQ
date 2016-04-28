/*
** my_strncmp.c for my_strncmp.c in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 14:18:14 2015 Ronan Boiteau
** Last update Thu Dec 17 23:23:40 2015 Ronan Boiteau
*/

#include "my.h"

int		my_strncmp(const char *str1, const char *str2, uint nbr)
{
  uint		idx;

  idx = 0;
  while (str1[idx] != '\0' && str2[idx] != '\0' && idx < nbr)
    {
      if (str1[idx] != str2[idx])
	return (str1[idx] - str2[idx]);
      idx += 1;
    }
  return (0);
}
