#include "my.h"
#include "bsq_board.h"
#include "bsq_solver.h"

static int	_is_square(const t_board *board,
			   const uint this_line,
			   const uint this_col,
			   uint largest)
{
  uint		tmp;
  uint		tmp_col;

  tmp_col = this_col;
  while (tmp_col < this_col + largest)
    {
      tmp = 1;
      while (tmp < largest &&
	     (this_line + tmp) < board->lines &&
	     board->tab[this_line + tmp][tmp_col] != 'o')
	tmp += 1;
      if (tmp != largest)
	return (FALSE);
      tmp_col += 1;
    }
  return (TRUE);
}

static void	_scan_squares(t_coords *square,
			      const t_board *board,
			      const int this_line,
			      const int this_col)
{
  uint		largest;

  largest = 0;
  while (board->tab[this_line][this_col + largest] &&
	 board->tab[this_line][this_col + largest] != 'o' &&
	 board->tab[this_line][this_col + largest] != C_EOL)
    largest += 1;
  while (largest > square->size && !_is_square(board, this_line, this_col, largest))
    largest -= 1;
  if (largest > square->size)
    {
      square->size = largest;
      square->line = this_line;
      square->column = this_col;
    }
  return ;
}

void		_solve(const t_board *board, t_coords *square)
{
  uint		idx_line;
  uint		idx_col;

  idx_line = 0;
  while (idx_line < board->lines)
    {
      idx_col = 0;
      while (idx_col <= board->cols && board->tab[idx_line][idx_col] != C_EOL)
	{
	  _scan_squares(square, board, idx_line, idx_col);
	  idx_col += 1;
	}
      idx_line += 1;
    }
  return ;
}
