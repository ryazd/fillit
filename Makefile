.PHONY: all libmake fillit clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft -lft
NAME = fillit
SOURCES = fillit.c fillit_figures.c fillit_lists.c \
		  fillit_others.c fillit_print.c
OBJECTS = $(subst .c,.o,$(SOURCES))

all: $(NAME)

libmake:
	@(cd libft; make)

$(NAME): libmake $(OBJECTS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@(cd libft; make clean)
	@rm -rf $(OBJECTS)

fclean: clean
	@(cd libft; make fclean)
	@rm -rf $(NAME)

re: fclean all
