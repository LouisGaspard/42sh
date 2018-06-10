##
## EPITECH PROJECT, 2018
## unitair
## File description:
## unitair
##

SRC_DIR		=	$(realpath ../src)

SRC		=	$(SRC_DIR)/my_shell.c			\
			$(SRC_DIR)/my_get_next_line.c		\
			$(SRC_DIR)/my_copy_env.c		\
			$(SRC_DIR)/my_init_base_cmd.c		\
			$(SRC_DIR)/my_copy_tab_repeat.c		\
			$(SRC_DIR)/my_create_env.c		\
			$(SRC_DIR)/my_init_tab_built.c		\
			$(SRC_DIR)/my_init_struct_null.c        \
			$(SRC_DIR)/my_search_save_path.c        \
			$(SRC_DIR)/my_get_prompt.c              \
			$(SRC_DIR)/my_parsing.c                 \
			$(SRC_DIR)/my_free_tab.c                \
			$(SRC_DIR)/my_pwd.c                     \
			$(SRC_DIR)/my_realloc.c                 \
			$(SRC_DIR)/my_error.c                   \
			$(SRC_DIR)/my_path.c                    \
			$(SRC_DIR)/my_redirections.c            \
			$(SRC_DIR)/my_pipes.c                   \
			$(SRC_DIR)/my_pipes_utils.c             \
			$(SRC_DIR)/builtins/my_cd.c             \
			$(SRC_DIR)/builtins/my_which.c          \
			$(SRC_DIR)/builtins/my_setenv.c         \
			$(SRC_DIR)/builtins/my_unsetenv.c       \
			$(SRC_DIR)/builtins/my_alias.c          \
			$(SRC_DIR)/builtins/my_where.c          \
			$(SRC_DIR)/builtins/my_env.c            \
			$(SRC_DIR)/builtins/my_echo.c           \
			$(SRC_DIR)/builtins/my_exit.c           \
			$(SRC_DIR)/builtins/my_history.c        \
			$(SRC_DIR)/builtins/my_repeat.c         \
			$(SRC_DIR)/shell_toolbox/my_strcat.c            \
			$(SRC_DIR)/shell_toolbox/my_str_to_word_array.c \
			$(SRC_DIR)/shell_toolbox/my_strstr.c            \
			$(SRC_DIR)/shell_toolbox/my_str_isnum.c         \
			$(SRC_DIR)/shell_toolbox/my_str_isalphanum.c    \
			$(SRC_DIR)/shell_toolbox/my_is_alphanum.c       \
			$(SRC_DIR)/shell_toolbox/my_show_word_array.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/tests_copy_env.c	\
			$(SRC_UT_DIR)/tests_free_tab.c	\
			$(SRC_UT_DIR)/tests_env.c	\
			$(SRC_UT_DIR)/tests_cd.c	\
			$(SRC_UT_DIR)/tests_alias.c	\
			$(SRC_UT_DIR)/tests_echo.c	\
			$(SRC_UT_DIR)/tests_repeat.c	\

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra

CFLAGS		+=	-I ../include

LDFLAGS		=	-lcriterion -lgcov

NAME		=	units

CC		=	gcc --coverage

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_DIR)/builtins/*.g*
		rm -f $(SRC_DIR)/shell_toolbox/*.g*
		rm -f $(SRC_UT_DIR)/*g*

fclean:		clean
		rm -f $(NAME)

re:		fclean all
