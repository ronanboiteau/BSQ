/*
** bsq_board.h for bsq in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Dec 15 17:33:43 2015 Ronan Boiteau
** Last update Fri Dec 18 21:30:07 2015 Ronan Boiteau
*/

#ifndef BSQ_BOARD_H_
# define BSQ_BOARD_H_

# include "my_macro.h"
# include <sys/stat.h>
# include <fcntl.h>

# define EXIT_WARNING 2
# define ERR_MAP ("No valid map in file \"%s\"\n")
# define ALERT "\x1B[1;31m"
# define RESET "\x1B[0m"

typedef struct	s_board
{
  char		**tab;
  uint		lines;
  uint		cols;
  uint		size;
  int		warning;
}		t_board;

void		_get_board(const char *filepath,
			   t_board *board,
			   int verbose);
void		_check_file_content(char *content,
				    const char *filepath,
				    uint columns);
uint		_check_cols_lines(char *content,
				  const char *filepath,
				  uint columns);

#endif /* !BSQ_BOARD_H_ */
