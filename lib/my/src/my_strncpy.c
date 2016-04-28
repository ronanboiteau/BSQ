/*
** my_strncpy.c for my_strncpy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct  5 09:38:55 2015 Ronan Boiteau
** Last update Thu Dec 17 23:23:52 2015 Ronan Boiteau
*/

#include "my.h"

char		*my_strncpy(char *dest, const char *src, uint nbr)
{
  uint		idx;

  idx = 0;
  while (src[idx] != '\0' && idx < nbr)
    {
      dest[idx] = src[idx];
      idx += 1;
    }
  dest[idx] = '\0';
  return (dest);
}
