/*
** my_strlowcase.c for my_strlowcase in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 17:10:13 2015 Ronan Boiteau
** Last update Thu Dec 17 23:23:30 2015 Ronan Boiteau
*/

#include "my.h"

char		*my_strlowcase(char *str)
{
  uint		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] >= 'A' && str[idx] <= 'Z')
	str[idx] = str[idx] + 32;
      idx += 1;
    }
  return (str);
}
