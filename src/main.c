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
  my_exit(EXIT_FAILURE, "Usage: ./bsq [-cv] [FILE]" EOL
	  "Try './bsq --help' for more information." EOL);
  return (0);
}

static void	_print_help(char *options)
{
  my_printf("Usage: ./bsq [-cv] [BOARD FILE]" EOL);
  my_printf("Solve BSQ boards." EOL
	    "You can find a perl boards generator on your Epitech intranet."
	    EOL
	    EOL);
  my_printf("Options:" EOL
	    "  -c\tColorized output" EOL
	    "  -v\tVerbose mode" EOL
	    EOL);
  my_printf("Exit status:" EOL
	    " 0  if OK" EOL
	    " 1  if critical error (e.g., cannot retrieve board)" EOL
	    " 2  if minor warning (e.g., wrong board file auto-corrected)"
	    EOL);
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
  board->warning = FALSE;
  if (stat(filepath, &file_data) == -1)
    my_exit(EXIT_FAILURE, "stat() failed!" EOL);
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
    my_exit(EXIT_FAILURE, "Usage: ./bsq [-cv] [BOARD FILE]" EOL);
  filepath_idx = _find_filepath(argc, argv);
  options = _get_options(argv);
  if (my_strstr(options, "-help"))
    _print_help(options);
  _init_structs(&board, &square, argv[filepath_idx]);
  _get_board(argv[filepath_idx], &board, _is_option_active(options, 'v'));
  if (_is_option_active(options, 'v') == TRUE)
    my_printf("Solving BSQ..." EOL);
  _solve(&board, &square);
  if (_is_option_active(options, 'v') == TRUE)
    my_printf("Preparing to print completed BSQ board..." EOL);
  _print_result(&square, &board, _is_option_active(options, 'c'));
  my_free_2d_tab(board.tab, board.lines);
  free(options);
  if (board.warning == TRUE)
    return (EXIT_WARNING);
  else
    return (EXIT_SUCCESS);
}
