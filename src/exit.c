#include <stdlib.h>
#include "my.h"
#include "bsq_board.h"

void		_get_file_content_exit(char *content, const char *filepath)
{
  free(content);
  my_exit(EXIT_FAILURE, "Can't access file \"%s\"\n", filepath);
  return ;
}

void		_check_file_exit(char *content, const char *filepath)
{
  free(content);
  my_exit(EXIT_FAILURE, ERR_MAP, filepath);
  return ;
}
