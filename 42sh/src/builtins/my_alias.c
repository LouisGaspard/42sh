/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"
#include "get_next_line.h"

void	show_alias(t_shell *st)
{
	if (!(st->ali.name && st->ali.command)) {
		return;
	}
	for (int i = 0; (st->ali.name[i] && st->ali.command[i]); i++)
		printf("%s\t%s\n", st->ali.name[i], st->ali.command[i]);
}

int	alias_exist(char **exec, t_shell *st)
{
	int	i = 0;

	if (!exec[2] && exec[1]) {
		for (i = 0; st->ali.name[i] && st->ali.command[i] && \
strcmp(st->ali.name[i], exec[1]) != 0; i++);
		printf("%s", st->ali.command[i]);
		return (0);
	}
	for (i = 0; st->ali.name[i] && strcmp(st->ali.name[i], \
exec[1]) != 0; i++);
	if (st->ali.name[i] && strcmp(st->ali.name[i], exec[1]) == 0 && \
exec[1] && exec[2]) {
		free(st->ali.command[i]);
		st->ali.command[i] = strdup(exec[2]);
		return (0);
	}
	return (1);
}

int	my_alias(t_shell *st, char **exec)
{
	if (exec[0] != NULL && !exec[1] && !exec[2]) {
		show_alias(st);
		return (0);
	}
	if (!(st->ali.name)) {
		if (!exec[2])
			return (0);
		st->ali.name = malloc(sizeof(char *) * 2);
		st->ali.name[0] = strdup(exec[1]);
		st->ali.name[1] = NULL;
		st->ali.command = malloc(sizeof(char *) * 2);
		st->ali.command[0] = strdup(exec[2]);
		st->ali.command[1] = NULL;
	} else if (alias_exist(exec, st) == 1) {
		st->ali.name = realloc_my_env(st->ali.name, exec[1], 0);
		st->ali.command = realloc_my_env(st->ali.command, exec[2], 0);
	}
	return (0);
}

void	alias_search(t_shell *shell)
{
	for (int i = 0; shell->ali.name[i]; i++) {
		if (strcmp(shell->ali.name[i], shell->command[0]) == 0) {
			free(shell->command[0]);
			shell->command[0] = strdup(shell->ali.command[i]);
			alias_search(shell);
		}
	}
}
