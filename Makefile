##
## Makefile for bsq in /home/boitea_r/c/bsq/CPE_2015_BSQ
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Mon Dec 21 12:05:25 2015 Ronan Boiteau
## Last update Mon Dec 21 12:05:25 2015 Ronan Boiteau
##

NAME	= bsq

IDIR	= include/
IDIR_MY	= lib/my/include/

LIB	= libmy.a
LNAME	= my
LDIR	= lib/my

CC	= gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -ansi
CFLAGS	+= -Werror

SRCS_DIR	= src/
SRCS_FILES	= check_file.c		\
		  exit.c		\
		  get_content.c		\
		  main.c		\
		  options.c		\
		  print.c		\
		  solver.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
