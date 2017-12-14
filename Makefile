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
	$(CC) -o $(NAME) $(OBJS) -L $(LDIR) -l $(LNAME)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
