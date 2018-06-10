/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** exit
*/

#include "42sh.h"

int	my_exit(t_shell *shell, char **command)
{
	int     exit_value = 0;

	if (command[1] != NULL) {
		if (my_str_isnum(command[1]) == 0)
			exit_value = atoi(command[1]);
		else {
			fprintf(stderr, "%s%s", command[0], ERR_EXIT);
			shell->r_value = 1;
			return (0);
		}
	}
	free_all(shell);
	free_tab(shell->env);
	exit(exit_value);
}
