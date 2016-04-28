#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "bsq_board.h"
#include "bsq_solver.h"
#include "bsq_print.h"

static void	_draw_square(const t_coords *square, char **final_board)
{
  unsigned int	idx_line;
  unsigned int	idx_col;

  idx_line = 0;
  while (idx_line < square->size)
    {
      idx_col = 0;
      while (idx_col < square->size)
	{
	  final_board[square->line + idx_line][square->column + idx_col] = 'x';
	  idx_col += 1;
	}
      idx_line += 1;
    }
  return ;
}

static void	_print_this_char(const char this_char, int color_mode)
{
  if (color_mode == true)
    {
      if (this_char == 'x')
	my_printf(COLOR_CROSS "%c" RESET, this_char);
      else if (this_char == 'o')
	my_printf(COLOR_OBSTACLE "%c" RESET, this_char);
      else if (this_char == '.')
	my_printf(COLOR_DOT "%c" RESET, this_char);
      else
	my_printf("%c", this_char);
    }
  else
    my_printf("%c", this_char);
  return ;
}

void		_print_result(const t_coords *square,
			      const t_board *board,
			      int color_mode)
{
  unsigned int	idx_line;
  unsigned int	idx_col;
  char		**final_board;

  if ((final_board = malloc(sizeof(char *) * (board->lines + 1))) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  idx_line = 0;
  while (idx_line < board->lines)
    {
      if ((final_board[idx_line] = malloc(sizeof(char *) * (board->cols + 1))) == NULL)
	my_exit(EXIT_FAILURE, ERR_MALLOC);
      idx_col = 0;
      while (idx_col <= board->cols)
	{
	  final_board[idx_line][idx_col] = board->tab[idx_line][idx_col];
	  idx_col += 1;
	}
      idx_line += 1;
    }
  final_board[idx_line] = NULL;
  _draw_square(square, final_board);
  idx_line = 0;
  while (idx_line < board->lines)
    {
      idx_col = 0;
      while (idx_col <= board->cols)
	{
	  _print_this_char(final_board[idx_line][idx_col], color_mode);
	  idx_col += 1;
	}
      idx_line += 1;
    }
  my_free_2d_tab(final_board);
}
