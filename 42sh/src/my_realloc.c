/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** ...
*/

#include "42sh.h"

char    **realloc_my_env(char **env, char *var, char *str)
{
	int     nb_line = count_line(env);
	int     y = 0;
	char    **tab;

	tab = malloc(sizeof(char *) * (nb_line + 2));
	while (env[y]) {
		tab[y] = strdup(env[y]);
		y++;
	}
	if (str == NULL)
		tab[y] = strdup(var);
	else
		tab[y] = my_strcat(var, str);
	tab[y + 1] = NULL;
	free_tab(env);
	return (tab);
}
