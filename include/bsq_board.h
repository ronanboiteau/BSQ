#ifndef BSQ_BOARD_H_
# define BSQ_BOARD_H_

# include <sys/stat.h>
# include <fcntl.h>
# include "my_macro.h"

# define EXIT_WARNING 2
# define ERR_MAP ("No valid map in file \"%s\"\n")
# define ERR_MALLOC ("Out of memory! malloc() failed...\n")
# define ALERT "\x1B[1;31m"
# define RESET "\x1B[0m"

typedef struct	s_board
{
  char		**tab;
  unsigned int	lines;
  unsigned int	cols;
  unsigned int	size;
  int		warning;
}		t_board;

void		_get_board(const char *filepath,
			   t_board *board,
			   int verbose);
void		_check_file_content(char *content,
				    const char *filepath,
				    unsigned int columns);
unsigned int	_check_cols_lines(char *content,
				  const char *filepath,
				  unsigned int columns);

#endif /* !BSQ_BOARD_H_ */
