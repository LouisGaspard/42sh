/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"
#include "get_next_line.h"

void	free_all(t_shell *shell)
{
	if (shell->pipe != NULL && shell->pipe[0] != NULL)
		free_tab(shell->pipe);
	if (shell->separator != NULL && shell->separator[0] != NULL)
		free_tab(shell->separator);
	if (shell->tab_path != NULL && shell->tab_path[0] != NULL)
		free_tab(shell->tab_path);
	if (shell->str != NULL)
		free(shell->str);
}

void	ctrl_c(int a)
{
	(void)a;
	printf("\n$> ");
}

void	my_prompt(t_shell *shell)
{
	if (isatty(0) == 1) {
		printf("\033[4;34m%s\033[0m", shell->user_name);
		printf("\033[1;37m:\033[0m");
		printf("\033[1;31m%s\033[0m", shell->directory);
		printf("> ");
	}
}

int	check_null_command(t_shell *shell)
{
	int	i = 0;
	int	cpt = 0;

	while (shell->str[i]) {
		if (shell->str[i] != '|' && shell->str[i] != ' ')
			cpt++;
		i++;
	}
	if (cpt == 0) {
		fprintf(stderr, "Invalid null command.\n");
		my_prompt(shell);
		return ((shell->r_value = 1), 1);
	}
	return (0);
}

void	my_shell(t_shell *shell)
{
	signal(SIGINT, ctrl_c);
	my_prompt(shell);
	while ((shell->str = get_next_line(0))) {
		if (shell->str[0] == 0 || shell->str == NULL) {
			my_prompt(shell);
			continue;
		}
		if (check_null_command(shell) == 1)
			continue;
		shell->tab_path = search_path(shell->env);
		if (shell->tab_path == NULL || !shell->tab_path[0])
			shell->tab_path = my_str_to_word_array(\
(shell->save_path + 5), ":");
		shell->separator = my_str_to_word_array(shell->str, ";");
		parse_separator(shell);
		free_all(shell);
		shell->directory = get_curr_dir(shell->env);
		shell->user_name = get_curr_name(shell->env);
		my_prompt(shell);
	}
}
