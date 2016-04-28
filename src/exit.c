/*
** exit.c for bsq in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Dec 19 15:22:20 2015 Ronan Boiteau
** Last update Sat Dec 19 15:23:04 2015 Ronan Boiteau
*/

#include "my.h"
#include "bsq_board.h"

void		_get_file_content_exit(char *content, const char *filepath)
{
  free(content);
  my_exit(EXIT_FAILURE, "Can't access file \"%s\"" EOL, filepath);
  return ;
}

void		_check_file_exit(char *content, const char *filepath)
{
  free(content);
  my_exit(EXIT_FAILURE, ERR_MAP, filepath);
  return ;
}
