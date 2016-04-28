/*
** nmatch.c for nmatch in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Oct 10 22:11:14 2015 Ronan Boiteau
** Last update Tue Nov 24 00:53:02 2015 Ronan Boiteau
*/

#include "my.h"

int	nmatch(const char *str1, const char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return (0);
  else if ((*str1 == '\0') && (*str2 == '\0'))
    return (1);
  else if ((*str1 != '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1) + nmatch(str1 + 1, str2));
  else if ((*str1 == '\0') && (*str2 == '*'))
    return (nmatch(str1, str2 + 1));
  else if ((*str2 != '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2) + nmatch(str1, str2 + 1));
  else if ((*str2 == '\0') && (*str1 == '*'))
    return (nmatch(str1 + 1, str2));
  else if (*str1 == *str2)
    return (nmatch(str1 + 1, str2 + 1));
  else
    return (0);
}
