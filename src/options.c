#include "my.h"

int		_is_option_active(const char *opt_list, const char option)
{
  uint		idx;

  idx = 0;
  while (opt_list != NULL && opt_list[idx])
    {
      if (opt_list[idx] == option)
	return (TRUE);
      idx += 1;
    }
  return (FALSE);
}

static void	_check_options_exit(char *opt,
				    char *authorized_opt,
				    const char wrong_opt)
{
  free(opt);
  free(authorized_opt);
  my_exit(EXIT_FAILURE, "bsq: invalid option -- '%c'" EOL, wrong_opt);
  return ;
}

static void	_check_options(char *opt)
{
  uint		idx;
  uint		idx_auth;
  int		found_opt;
  char		*authorized_opt;

  authorized_opt = my_strdup("cv");
  idx = 0;
  while (opt != NULL && opt[idx])
    {
      idx_auth = 0;
      found_opt = FALSE;
      while (authorized_opt[idx_auth])
	{
	  if (opt[idx] == authorized_opt[idx_auth])
	    found_opt = TRUE;
	  idx_auth += 1;
	}
      if (found_opt == FALSE)
	{
	  if (!my_strstr(opt, "-help"))
	    _check_options_exit(opt, authorized_opt, opt[idx]);
	}
      idx += 1;
    }
  free(authorized_opt);
}

char		*_get_options(char **argv)
{
  uint		idx;
  char		*new_opt;
  char		*options;

  options = NULL;
  idx = 1;
  while (argv[idx])
    {
      if (argv[idx][0] == '-')
	{
	  new_opt = NULL;
	  if ((new_opt = malloc(sizeof(char) * my_strlen(argv[idx]) +
	  			my_strlen(options) + 1)) == NULL)
	    my_exit(EXIT_FAILURE, ERR_MALLOC);
	  if (options != NULL)
	    my_strncpy(new_opt, options, my_strlen(options));
	  free(options);
	  options = my_strncat(new_opt, argv[idx] + 1,
	  		       my_strlen(argv[idx] + 1));
	}
      idx += 1;
    }
  _check_options(options);
  return (options);
}
