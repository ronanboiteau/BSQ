/*
** my_min_int_tab.c for my_min_int_tab in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Nov  2 23:01:00 2015 Ronan Boiteau
** Last update Thu Dec 17 23:12:18 2015 Ronan Boiteau
*/

#include "my.h"

int		my_min_int_tab(const int *tab, const uint size)
{
  uint		idx;
  int		lowest;

  idx = 0;
  lowest = tab[idx];
  while (idx < size)
    {
      if (tab[idx] > lowest)
	lowest = tab[idx];
      idx += 1;
    }
  return (lowest);
}
