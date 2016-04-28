#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "bsq_board.h"
#include "bsq_exit.h"

static void	_check_lines(char *content, const char *filepath)
{
  unsigned int	idx;
  int		digit_found;

  digit_found = false;
  idx = 0;
  while (content[idx])
    {
      if (content[idx] == '\n')
	{
	  if (digit_found == false)
	    _check_file_exit(content, filepath);
	  return ;
	}
      else if (!(content[idx] >= '0' && content[idx] <= '9'))
	_check_file_exit(content, filepath);
      else if (content[idx] >= '0' && content[idx] <= '9')
	digit_found = true;
      idx += 1;
    }
  if (content[idx - 1] != '\n')
    _check_file_exit(content, filepath);
  return ;
}

static void	_check_board(char *content, const char *filepath)
{
  unsigned int	idx;

  idx = 0;
  while (content[idx] != '\n')
    idx += 1;
  while (content[idx])
    {
      if (content[idx] != '.' && content[idx] != 'o' && content[idx] != '\n')
	_check_file_exit(content, filepath);
      idx += 1;
    }
  if (content[idx - 1] && content[idx - 1] != '\n')
    _check_file_exit(content, filepath);
  return ;
}

unsigned int		_check_cols_lines(char *content,
					  const char *filepath,
					  unsigned int columns)
{
  unsigned int		idx;
  unsigned int		tmp_columns;
  static unsigned int	lines;

  if (content == NULL)
    return (lines);
  lines = 0;
  idx = 0;
  while (content[idx] != '\n')
    idx += 1;
  idx += 1;
  tmp_columns = 1;
  while (content[idx])
    {
      if (content[idx] == '\n')
	{
	  lines += 1;
	  if (tmp_columns - 1 != columns)
	    _check_file_exit(content, filepath);
	  tmp_columns = 0;
	}
      tmp_columns += 1;
      idx += 1;
    }
  return (0);
}

void		_check_file_content(char *content,
				    const char *filepath,
				    unsigned int columns)
{
  _check_lines(content, filepath);
  _check_cols_lines(content, filepath, columns);
  _check_board(content, filepath);
  return ;
}
