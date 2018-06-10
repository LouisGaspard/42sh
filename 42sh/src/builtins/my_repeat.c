/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "42sh.h"

int	too_few_arg_or_bad_number(char **tab, t_shell *shell)
{
	if (tab[1] == NULL || tab[2] == NULL) {
		printf("%s: Too few arguments\n", tab[0]);
		shell->r_value = 1;
		return (shell->r_value);
	}
	if (my_str_isnum(tab[1]) == 1) {
		printf("%s: Badly formed number\n", tab[0]);
		shell->r_value = 1;
		return (shell->r_value);
	}
	return (0);
}

void	check_loop_display(int nb, char **tab, char *save, t_shell *st)
{
	int	compteur = 0;
	int	pid;
	int	status = 0;

	while (compteur != nb) {
		pid = fork();
		if (pid == 0) {
			tab = stack_my_tab(tab);
			execve(save, tab, st->env);
		}
		compteur += 1;
		waitpid(pid, &status, 0);
	}
}

int	verif_for_repeat(int nb, char *save, char **tab, t_shell *st)
{
	int	cpt = 0;

	if (access(save, X_OK || F_OK) != -1) {
		cpt = 1;
		check_loop_display(nb, tab, save, st);
	}
	return (cpt);
}

void	my_repeat_no_built(t_shell *shell, char **tab, int nb)
{
	char	*save;
	int	cpt = 0;

	for (int y = 0; (shell->tab_path[y]); y++) {
		cpt = 0;
		save = my_strcat(shell->tab_path[y], "/");
		save = my_strcat(save, tab[2]);
		cpt = verif_for_repeat(nb, save, tab, shell);
		if (cpt == 1)
			break;
	}
	if (cpt == 0) {
		printf("%s%s", tab[0], ERR_NOT_FOUND);
		return;
	}
}

int     my_repeat(t_shell *shell, char **tab)
{
	char	**arg_tab;
	int	nb;

	if (too_few_arg_or_bad_number(tab, shell) == 1)
		return (1);
	nb = atoi(tab[1]);
	arg_tab = stack_my_tab(tab);
	if (cmd_is_builtins(arg_tab, shell) == 1) {
		for (int i = 1; i != nb; i++)
			cmd_is_builtins(arg_tab, shell);
		return (0);
	}
	my_repeat_no_built(shell, tab, nb);
	return (shell->r_value);
}
