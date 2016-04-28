#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bsq_board.h"
#include "bsq_exit.h"

static char		*_get_file_content(const char *filepath, t_board *board)
{
  unsigned int		idx;
  char			*content;
  int			fd;
  int			eol;

  if ((content = malloc(sizeof(char) * (board->size + 1))) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  if ((fd = open(filepath, O_RDONLY)) == -1)
    _get_file_content_exit(content, filepath);
  eol = 0;
  if (!read(fd, content, board->size))
    my_exit(EXIT_FAILURE, ERR_MAP, filepath);
  content[board->size] = '\0';
  idx = 0;
  while (content[idx] && eol < 2)
    {
      if (content[idx] == '\n')
  	eol += 1;
      else if (eol == 1)
  	board->cols += 1;
      idx += 1;
    }
  if (close(fd) == -1)
    _get_file_content_exit(content, filepath);
  return (content);
}

static void	_str_to_chartab(const char *str, t_board *board)
{
  unsigned int	idx_str;
  unsigned int	idx_line;
  unsigned int	idx_col;

  if ((board->tab = malloc(sizeof(char *) * (board->lines + 1))) == NULL)
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
  board->tab[idx_line] = NULL;
  return ;
}

static char	*_get_lines_str(char *file_content)
{
  unsigned int	idx;
  char		*lines_str;

  idx = 0;
  while (file_content[idx] != '\n')
    idx += 1;
  if ((lines_str = malloc(sizeof(char) * (idx + 1))) == NULL)
    my_exit(EXIT_FAILURE, ERR_MALLOC);
  idx = 0;
  while (file_content[idx] != '\n')
    {
      lines_str[idx] = file_content[idx];
      idx += 1;
    }
  lines_str[idx] = '\0';
  return (lines_str);
}

static char	*_get_board_ptr(char *file_content)
{
  char		*board_str;

  board_str = file_content;
  while (board_str[0] != '\n')
    board_str += 1;
  board_str += 1;
  return (board_str);
}

void		_get_board(const char *filepath, t_board *board, int verbose)
{
  char		*file_content;
  char		*board_str;
  char		*lines_str;

  if (verbose == true)
    my_printf("Accessing file...\n");
  file_content = _get_file_content(filepath, board);
  if (verbose == true)
    my_printf("Checking file content...\n");
  _check_file_content(file_content, filepath, board->cols);
  board->lines = my_atoi((lines_str = _get_lines_str(file_content)));
  if (_check_cols_lines(NULL, NULL, board->cols) != board->lines)
    {
      my_dprintf(STDERR, ALERT "WARNING: " RESET "number of lines found in "
		 "file is incorrect! It has been automatically corrected.\n");
      board->lines = _check_cols_lines(NULL, NULL, board->cols);
      board->warning = true;
    }
  if (verbose == true)
    my_printf("Retrieving BSQ board...\n");
  board_str = _get_board_ptr(file_content);
  _str_to_chartab(board_str, board);
  free(lines_str);
  free(file_content);
}
