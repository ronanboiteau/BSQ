#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "bsq_board.h"
#include "bsq_print.h"
#include "bsq_options.h"
#include "bsq_solver.h"

static int	_find_filepath(int argc, char **argv)
{
  int		idx;

  idx = 1;
  while (idx < argc)
    {
      if (argv[idx][0] != '-')
	return (idx);
      idx += 1;
    }
  my_exit(EXIT_FAILURE, "Usage: ./bsq [-cv] [FILE]\n"
	  "Try './bsq --help' for more information.\n");
  return (0);
}

static void	_print_help(char *options)
{
  my_printf("Usage: ./bsq [-cv] [BOARD FILE]\n");
  my_printf("Solves BSQ boards.\n\n");
  my_printf("Options:\n"
	    "  -c\tColorized output\n"
	    "  -v\tVerbose mode\n\n");
  my_printf("Exit status:\n"
	    " 0 -> OK\n"
	    " 1 -> Critical error (e.g., cannot retrieve board)\n"
	    " 2 -> Minor warning (e.g., automatically-fixed a wrong board file)\n");
  free(options);
  my_exit(EXIT_SUCCESS, NULL);
}

static void	_init_structs(t_board *board,
			      t_coords *square,
			      const char *filepath)
{
  struct stat	file_data;

  square->size = 0;
  square->line = 0;
  square->column = 0;
  board->tab = NULL;
  board->lines = 0;
  board->cols = 0;
  board->warning = false;
  if (stat(filepath, &file_data) == -1)
    my_exit(EXIT_FAILURE, "stat() failed!\n");
  board->size = file_data.st_size;
  return ;
}

int		main(int argc, char **argv)
{
  t_board	board;
  t_coords	square;
  char		*options;
  int		filepath_idx;

  if (argc < 2)
    my_exit(EXIT_FAILURE, "Usage: ./bsq [-cv] [BOARD FILE]\n");
  filepath_idx = _find_filepath(argc, argv);
  options = _get_options(argv);
  if (my_strstr(options, "-help"))
    _print_help(options);
  _init_structs(&board, &square, argv[filepath_idx]);
  _get_board(argv[filepath_idx], &board, _is_option_active(options, 'v'));
  if (_is_option_active(options, 'v') == true)
    my_printf("Solving BSQ...\n");
  _solve(&board, &square);
  if (_is_option_active(options, 'v') == true)
    my_printf("Preparing to print completed BSQ board...\n");
  _print_result(&square, &board, _is_option_active(options, 'c'));
  my_free_2d_tab(board.tab);
  free(options);
  if (board.warning == true)
    return (EXIT_WARNING);
  else
    return (EXIT_SUCCESS);
}
