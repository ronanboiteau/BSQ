/*
** get_content.c for bsq in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Dec 14 18:22:04 2015 Ronan Boiteau
** Last update Sat Dec 19 15:33:32 2015 Ronan Boiteau
*/

#include "my.h"
#include "bsq_board.h"
#include "bsq_exit.h"

static char	*_get_file_content(const char *filepath,
				   t_board *board)
{
  uint		idx;
  char		*content;
  int		fd;
  int		eol;

  if ((content = malloc(sizeof(char) * (board->size + 1))) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  if ((fd = open(filepath, O_RDONLY)) == -1)
    _get_file_content_exit(content, filepath);
  eol = 0;
  if (!read(fd, content, board->size))
    my_exit(EXIT_FAILURE, ERR_MAP, filepath);
  content[board->size] = C_NUL;
  idx = 0;
  while (content[idx] && eol < 2)
    {
      if (content[idx] == C_EOL)
  	eol += 1;
      else if (eol == 1)
  	board->cols += 1;
      idx += 1;
    }
  if (close(fd) == -1)
    _get_file_content_exit(content, filepath);
  return (content);
}

static void	_str_to_chartab(const char *str,
				t_board *board)
{
  uint		idx_str;
  uint		idx_line;
  uint		idx_col;

  if ((board->tab = malloc(sizeof(char *) * board->lines)) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  idx_str = 0;
  idx_line = 0;
  while (idx_line < board->lines)
    {
      if ((board->tab[idx_line] = malloc(sizeof(char) * (board->cols + 1)))
	  == NULL)
	my_exit(EXIT_FAILURE, ERR_MALLOC);
      idx_col = 0;
      while (idx_col <= board->cols)
	{
	  board->tab[idx_line][idx_col] = str[idx_str];
	  idx_col += 1;
	  idx_str += 1;
	}
      idx_line += 1;
    }
  return ;
}

static char	*_get_lines_str(char *file_content)
{
  uint		idx;
  char		*lines_str;

  while (file_content[idx] != C_EOL)
    idx += 1;
  if ((lines_str = malloc(sizeof(char) * (idx + 1))) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  idx = 0;
  while (file_content[idx] != C_EOL)
    {
      lines_str[idx] = file_content[idx];
      idx += 1;
    }
  lines_str[idx] = C_NUL;
  return (lines_str);
}

static char	*_get_board_ptr(char *file_content)
{
  char		*board_str;

  board_str = file_content;
  while (board_str[0] != C_EOL)
    board_str += 1;
  board_str += 1;
  return (board_str);
}

void		_get_board(const char *filepath,
			   t_board *board,
			   int verbose)
{
  char		*file_content;
  char		*board_str;
  char		*lines_str;

  if (verbose == TRUE)
    my_printf("Accessing file..." EOL);
  file_content = _get_file_content(filepath, board);
  if (verbose == TRUE)
    my_printf("Checking file content..." EOL);
  _check_file_content(file_content, filepath, board->cols);
  board->lines = my_atoi((lines_str = _get_lines_str(file_content)));
  if (_check_cols_lines(NULL, NULL, board->cols) != board->lines)
    {
      my_dprintf(STDERR, ALERT "WARNING: " RESET "number of lines found in "
		 "file is incorrect! It has been automatically corrected."
		 EOL);
      board->lines = _check_cols_lines(NULL, NULL, board->cols);
      board->warning = TRUE;
    }
  if (verbose == TRUE)
    my_printf("Retrieving BSQ board..." EOL);
  board_str = _get_board_ptr(file_content);
  _str_to_chartab(board_str, board);
  free(lines_str);
  free(file_content);
}
