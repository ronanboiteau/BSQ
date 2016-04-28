/*
** my_free_2d_tab.c for libmy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Dec 16 17:55:52 2015 Ronan Boiteau
** Last update Thu Dec 17 23:38:08 2015 Ronan Boiteau
*/

#include "my.h"

void		my_free_2d_tab(char **tab, const uint lines)
{
  uint		idx;

  idx = 0;
  while (idx < lines)
    {
      free(tab[idx]);
      idx += 1;
    }
  free(tab);
  return ;
}
