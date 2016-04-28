/*
** bsq_solver.h for bsq in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Dec 14 23:07:33 2015 Ronan Boiteau
** Last update Fri Dec 18 23:31:25 2015 Ronan Boiteau
*/

#ifndef BSQ_SOLVER_H_
# define BSQ_SOLVER_H_

# include "bsq_board.h"
# include "my_macro.h"

typedef struct	s_coords
{
  uint		line;
  uint		column;
  uint		size;
}		t_coords;

void		_solve(const t_board *board, t_coords *square);

#endif /* !BSQ_SOLVER_H_ */
