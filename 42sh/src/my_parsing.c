/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"
#include "get_next_line.h"

int     get_built_nb(t_shell *shell, char **command)
{
	for (int i = 0; shell->built[i]; i++) {
		if (strcmp(command[0], shell->built[i]) == 0)
			return (i);
	}
	return (-1);
}

int     cmd_is_builtins(char **command, t_shell *shell)
{
	int     nb_cmd = get_built_nb(shell, command);

	if (nb_cmd == -1)
		return (0);
	(*shell->tab_cmd[nb_cmd])(shell, command);
	return (1);
}

void	exec_cmd(t_shell *shell)
{
	shell->command = pars_wordexp(shell->pipe[0]);
	if (shell->ali.name)
		alias_search(shell);
	if (cmd_is_builtins(shell->command, shell))
		return;
	if (my_command(shell, shell->env, shell->command, shell->tab_path))
		return;
}

void	parse_separator(t_shell *shell)
{
	int	a = 0;

	shell->nb_pipes = 0;
	while (shell->separator[a]) {
		shell->pipe = my_str_to_word_array(shell->separator[a], "|");
		shell->nb_pipes = count_line(shell->pipe);
		if (shell->nb_pipes > 1)
			loop_pipe(shell);
		else
			exec_cmd(shell);
		a++;
	}
}
