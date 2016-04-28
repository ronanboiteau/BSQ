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

LIB	= libmy.a
LNAME	= my
LDIR	= lib/my

CC	= gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra -ansi
CFLAGS	+= -Werror

SDIR	= src/
SRCS	= $(SDIR)check_file.c				\
	  $(SDIR)exit.c					\
	  $(SDIR)get_content.c				\
	  $(SDIR)main.c					\
	  $(SDIR)options.c				\
	  $(SDIR)print.c				\
	  $(SDIR)solver.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
