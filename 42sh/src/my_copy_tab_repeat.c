/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** repeat
*/

#include "42sh.h"

char	**stack_my_tab(char **tab)
{
	int     i = 2;
	int     y = 0;
	int     nb_word = (count_line(tab) - 2);
	char    **new = malloc(sizeof(char *) * (nb_word + 1));

	while (tab[i]) {
		new[y] = strdup(tab[i]);
		i++;
		y++;
	}
	new[y] = NULL;
	return (new);
}
