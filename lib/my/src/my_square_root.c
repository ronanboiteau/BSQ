/*
** my_square_root.c for my_square_root in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct  4 17:40:19 2015 Ronan Boiteau
** Last update Thu Dec 17 23:37:09 2015 Ronan Boiteau
*/

#include "my.h"

int		my_square_root(const int nbr)
{
  ll		tmp;
  int		result;

  result = 0;
  if (nbr >= 0)
    {
      while ((tmp = (ll)result * (ll)result) != nbr && result <= nbr)
	result += 1;
    }
  else
    return (0);
  if (result == nbr + 1)
    return (0);
  else
    return (result);
}
