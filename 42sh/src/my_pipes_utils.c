/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** pipes_utils
*/

#include "42sh.h"
#include "get_next_line.h"

void    exec_pipe(t_shell *sh)
{
	if (cmd_is_builtins(sh->command, sh))
		return;
	if (my_command_waitless(sh, sh->env, sh->command, sh->tab_path))
		return;
}

void    close_pipe(int *pipefds, int nb_pipes)
{
	int     i = 0;

	while (i < (2 * nb_pipes)) {
		close(pipefds[i]);
		i++;
	}
}

void    wait_pipe(t_shell *shell)
{
	int     i = 0;
	int     status = 0;

	for (i = 0; i < (shell->nb_pipes + 1); i++) {
		wait(&status);
		shell->r_value = status;
	}
}
