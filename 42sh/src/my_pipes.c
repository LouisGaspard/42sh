/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include <wordexp.h>
#include "42sh.h"
#include "get_next_line.h"

int     file_exist_waitless(char **file, char **my_env, char **tab)
{
	if (!access(file[0], X_OK || F_OK)) {
		execve(file[0], tab, my_env);
		return (1);
	}
	return (0);
}

int     my_command_waitless(t_shell *shell, char **my_env,
char **tab, char **tab_path)
{
	int   y = 0;
	char    *file[2];

	file[1] = NULL;
	if (check_if_i_have_slash(shell) == 1)
		return (1);
	if (tab_path == NULL) {
		fprintf(stderr, "%s%s", tab[0], ERR_NOT_FOUND);
		return ((shell->r_value = 1), 1);
	}
	while (tab_path[y]) {
		file[0] = my_strcat_path(tab_path[y], tab[0]);
		if ((file_exist_waitless(file, my_env, tab)) == 1) {
			free(file[0]);
			return (1);
		}
		y++;
	}
	fprintf(stderr, "%s%s", tab[0], ERR_NOT_FOUND);
	return ((shell->r_value = 1), 0);
}

char	**pars_wordexp(char *cmd)
{
	wordexp_t	exp;
	int		ret;

	ret = wordexp(cmd, &exp, WRDE_SHOWERR | WRDE_UNDEF);
	if (ret != EXIT_SUCCESS || my_strstr(cmd, "echo ") != NULL)
		return (my_str_to_word_array(cmd, " \t"));
	return (exp.we_wordv);
}

void	exec_process(t_shell *shell, int *fd, int *pipefds, int count)
{
	t_red	*red = parse_red(shell, count / 2);

	if (shell->pipe[count / 2 + 1] != NULL)
		dup2(pipefds[count + 1], 1);
	else {
		fd[1] = get_fd_1(red);
		dup2(fd[1], 1);
	}
	if (count != 0)
		dup2(pipefds[count - 2], 0);
	else {
		fd[0] = get_fd_0(red);
		dup2(fd[0], 0);
	}
	close_pipe(pipefds, shell->nb_pipes);
	shell->command = pars_wordexp(shell->pipe[count / 2]);
	exec_pipe(shell);
	exit(0);
}

void	loop_pipe(t_shell *shell)
{
	int	count = 0;
	int	pipefds[2 * shell->nb_pipes];
	int	i = 0;
	int	fd[2];
	pid_t	pid;

	fd[0] = 0;
	fd[1] = 1;
	for (i = 0; i < shell->nb_pipes; i++)
		pipe(pipefds + i * 2);
	while (shell->pipe[count / 2] != NULL) {
		pid = fork();
		if (pid == 0) {
			exec_process(shell, fd, pipefds, count);
		}
		count += 2;
	}
	close_pipe(pipefds, shell->nb_pipes);
	wait_pipe(shell);
}
