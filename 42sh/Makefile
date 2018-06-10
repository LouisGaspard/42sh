##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

NAME	= 	42sh

CC	= 	gcc

RM	= 	rm -f

SRCS	=	./src/main.c				\
		./src/my_shell.c			\
		./src/my_get_next_line.c		\
		./src/my_copy_env.c			\
		./src/my_init_base_cmd.c		\
		./src/my_copy_tab_repeat.c		\
		./src/my_create_env.c			\
		./src/my_init_tab_built.c		\
		./src/my_init_struct_null.c		\
		./src/my_search_save_path.c		\
		./src/my_get_prompt.c			\
		./src/my_parsing.c			\
		./src/my_free_tab.c			\
		./src/my_pwd.c				\
		./src/my_redirections.c			\
		./src/my_realloc.c			\
		./src/my_error.c			\
		./src/my_path.c				\
		./src/my_pipes.c			\
		./src/my_pipes_utils.c			\
		./src/builtins/my_cd.c			\
		./src/builtins/my_which.c		\
		./src/builtins/my_setenv.c		\
		./src/builtins/my_unsetenv.c		\
		./src/builtins/my_alias.c		\
		./src/builtins/my_where.c		\
		./src/builtins/my_env.c			\
		./src/builtins/my_echo.c		\
		./src/builtins/my_exit.c		\
		./src/builtins/my_history.c		\
		./src/builtins/my_repeat.c		\
		./src/shell_toolbox/my_strcat.c			\
		./src/shell_toolbox/my_str_to_word_array.c	\
		./src/shell_toolbox/my_strstr.c			\
		./src/shell_toolbox/my_str_isnum.c		\
		./src/shell_toolbox/my_str_isalphanum.c		\
		./src/shell_toolbox/my_is_alphanum.c		\
		./src/shell_toolbox/my_show_word_array.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS 	=	-I ./include/

CFLAGS 	+=	-W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

tests_run:
	make -C ./tests/
	./tests/units
	cp ./tests/*.gc* .

clean:
	make clean -C ./tests/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./tests/units
	$(RM) $(NAME)
	$(RM) *.gc*

re: fclean all

.PHONY: all clean fclean re
