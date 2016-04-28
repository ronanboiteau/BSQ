/*
** my_char_isprintable.c for my_char_isprintable in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:11:26 2015 Ronan Boiteau
** Last update Thu Dec 17 22:59:04 2015 Ronan Boiteau
*/

#include "my.h"

int		my_char_isprintable(const char letter)
{
  if (!(letter >= 32 && letter <= 126))
    return (FALSE);
  return (TRUE);
}
