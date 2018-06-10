/*
** EPITECH PROJECT, 2018
** 42
** File description:
** 42
*/

#ifndef	__42SH_H__
#define	__42SH_H__

#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/wait.h>

#define ERR_ACCESS	": No such file or directory.\n"
#define ERR_DIR		": Not a directory.\n"
#define ERR_HOME	": No home directory.\n"
#define ERR_FEW_ARG	": Too few arguments.\n"
#define ERR_NOT_FOUND	": Command not found.\n"
#define ERR_PERM	": Permission denied.\n"
#define ERR_EXIT	": Expression Syntax.\n"
#define ERR_SETENV_CHAR	": Variable name must contain alphanumeric"
#define ERR_SET		" characters.\n"
#define ERR_SETENV_ARG	": Too many arguments.\n"
#define ERR_SETENV_NAME	": Variable name must begin with a letter.\n"
#define ERR_SEG		"Segmentation fault\n"
#define ERR_FLOAT	"Floating exception\n"
#define ERR_ARCH	": Exec format error. Wrong Architecture.\n"

typedef struct
{
	char	**name;
	char	**command;
} t_alias;

typedef struct
{
	char	*directory;
	char	*user_name;
	char	*str;
	char	**env;
	char	**separator;
	char	**pipe;
	char	**command;
	char	*save_path;
	char	**tab_path;
	char	**built;
	int	(*tab_cmd[11])();
	int	r_value;
	int	nb_pipes;
	t_alias ali;
} t_shell;

typedef enum	e_keys
{
	RIGHT,
	DRIGHT,
	LEFT,
	DLEFT
} t_keys;

typedef struct
{
	char	**cmd;
	int	*type;
} t_red;

t_shell	init_struct_null(t_shell shell);
void	exec_pipe(t_shell *shell);
void	close_pipe(int *fdpipe, int nb_pipes);
void	wait_pipe(t_shell *shell);
void	my_shell(t_shell *shell);
void	parse_pipe(t_shell *shell, int nb_lines);
void	parse_separator(t_shell *shell);
void	free_all(t_shell *shell);
void	old_pwd(t_shell *sh);
void	maj_pwd(t_shell *sh);
void	alias_search(t_shell *shell);
void	loop_pipe(t_shell *shell);
void	init_base_cmd(int (**tab_cmd)());
char	*my_search_home(char **env);
char	*my_strcat(char *s1, char *s2);
char	*get_curr_dir(char **env);
char	*get_curr_name(char **env);
char	*my_strcat_path(char*, char*);
char	*my_strstr(char *s1, char const *s2);
char	*search_save(char **env);
char	**stack_my_tab(char **tab);
char	**pars_wordexp(char *cmd);
char	**init_tab_built(void);
char	**search_path(char **env);
char	**my_str_to_word_array(char *str, char *lim);
char	**copy_env(char **env);
char	**create_env(void);
char	**realloc_my_env(char **env, char *var, char *str);
int	do_cd(char **command, t_shell *sh);
int	my_unsetenv(t_shell *sh, char **command);
int	my_setenv(t_shell *shell, char **command);
int	my_where(t_shell *shell, char **command);
int	my_alias(t_shell *shell, char **command);
int	my_echo(t_shell *shell, char **command);
int	my_history(t_shell *shell, char **command);
int	my_repeat(t_shell *shell, char **command);
int	my_exit(t_shell *shell, char **command);
int	my_which(t_shell *shell, char **command);
int	which_loop(char **tab, char **tab_path, int j, int compt);
int	my_show_word_array(char * const *tab);
int	my_str_isnum(char const *str);
int	my_is_alphanum(char c);
int	my_str_isalphanum(char *str);
int	check_if_i_have_slash(t_shell *shell);
int	check_signal(t_shell *shell, int status);
int	free_tab(char **tab);
int	count_line(char **env);
int	my_char_isalpha(char c);
int	file_exist(char **file, char **my_env, char **tab);
int	my_command(t_shell *sh, char **env, char **tab1, char **tab2);
int	my_cd(t_shell *shell, char **command);
int	cmd_is_builtins(char **command, t_shell *shell);
int	my_env(t_shell *shell, char **command);
int	my_command_waitless(t_shell *shell, char **my_env,
char **tab, char **tab_path);
int	get_fd_1(t_red *red);
int	get_fd_0(t_red *red);
t_red	*parse_red(t_shell *shell, int count);

#endif
