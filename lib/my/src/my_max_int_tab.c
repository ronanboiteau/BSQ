/*
** my_max_int_tab.c for my_max_int_tab in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:48:15 2015 Ronan Boiteau
** Last update Thu Dec 17 22:54:17 2015 Ronan Boiteau
*/

#include "my.h"

int		my_max_int_tab(const int *tab, const uint size)
{
  uint		idx;
  int		greatest;

  idx = 0;
  greatest = tab[idx];
  while (idx < size)
    {
      if (tab[idx] > greatest)
	greatest = tab[idx];
      idx += 1;
    }
  return (greatest);
}
