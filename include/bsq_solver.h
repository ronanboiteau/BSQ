#ifndef BSQ_SOLVER_H_
# define BSQ_SOLVER_H_

# include "bsq_board.h"
# include "my_macro.h"

typedef struct	s_coords
{
  unsigned int	line;
  unsigned int	column;
  unsigned int	size;
}		t_coords;

void		_solve(const t_board *board, t_coords *square);

#endif /* !BSQ_SOLVER_H_ */
