/*
** bsq_print.h for bsq in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Dec 18 00:06:13 2015 Ronan Boiteau
** Last update Sat Dec 19 18:47:49 2015 Ronan Boiteau
*/

#ifndef BSQ_PRINT_H_
# define BSQ_PRINT_H_

# include "bsq_solver.h"
# include "bsq_board.h"

# define COLOR_OBSTACLE "\x1B[1;31m"
# define COLOR_CROSS "\x1B[1;32m"
# define COLOR_DOT "\x1B[1;33m"

void		_print_result(const t_coords *square,
			      const t_board *board,
			      int color_mode);

#endif /* !BSQ_PRINT_H_ */

