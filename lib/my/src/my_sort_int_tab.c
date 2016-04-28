/*
** my_sort_int_tab.c for my_sort_int_tab in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Oct 18 19:21:10 2015 Ronan Boiteau
** Last update Thu Dec 17 23:15:00 2015 Ronan Boiteau
*/

#include "my.h"

void		my_sort_int_tab(int *tab, int size)
{
  uint		idx;
  int		sorted;

  sorted = FALSE;
  while (!sorted)
    {
      sorted = TRUE;
      idx = 0;
      while (tab[idx + 1])
	{
	  if (tab[idx] > tab[idx + 1])
	    {
	      my_swap(&tab[idx], &tab[idx + 1]);
	      sorted = FALSE;
	    }
	  idx += 1;
	}
      my_max_int_tab(tab, size);
      idx += 1;
    }
  return ;
}
