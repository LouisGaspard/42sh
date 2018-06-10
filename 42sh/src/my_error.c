/*
** EPITECH PROJECT, 2018
** my_error.c
** File description:
** ..
*/

#include "42sh.h"

int     check_shlash(char *str)
{
	int     i = 0;

	while (str[i] != '\0') {
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

int     verif_my_execve(t_shell *shell)
{
	if ((execve(shell->command[0], shell->command, shell->env)) == -1) {
		fprintf(stderr, "%s%s", shell->command[0], ERR_ARCH);
		exit(-1);
	}
	return (0);
}

int	is_dir(char *repo_name)
{
	DIR	*repo;

	if ((repo = opendir(repo_name)) == NULL)
		return (0);
	closedir(repo);
	return (1);
}

int     check_if_i_have_slash(t_shell *sh)
{
	int	pid;
	int	status;

	if (check_shlash(sh->command[0]) == 0) {
		if (is_dir(sh->command[0]) == 1 && \
(!strncmp(sh->command[0], "./", 2) || \
sh->command[0][0] == '/')) {
			fprintf(stderr, "%s%s", sh->command[0], ERR_PERM);
			sh->r_value = 1;
			return (1);
		} else if (access(sh->command[0], X_OK || F_OK) == -1) {
			fprintf(stderr, "%s%s", sh->command[0], ERR_NOT_FOUND);
			sh->r_value = 1;
		}
		pid = fork();
		if (pid == 0)
			verif_my_execve(sh);
		waitpid(pid, &status, 0);
		return (check_signal(sh, status));
	}
	return (0);
}

int     check_signal(t_shell *shell, int status)
{
	if (WIFSIGNALED(status)) {
		if (WTERMSIG(status) == SIGSEGV) {
			fprintf(stderr, ERR_SEG);
			shell->r_value = 139;
		} else if (WTERMSIG(status) == SIGFPE) {
			fprintf(stderr, ERR_FLOAT);
			shell->r_value = 136;
		}
	}
	return (1);
}
