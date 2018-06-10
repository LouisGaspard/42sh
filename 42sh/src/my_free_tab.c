/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

int	free_tab(char **tab)
{
	int	a = 0;

	if (tab == NULL)
		return (1);
	if (tab[0] == NULL) {
		free(tab);
		return (0);
	}
	while (tab[a]) {
		if (tab[a] != NULL)
			free(tab[a]);
		a++;
	}
	free(tab);
	return (0);
}
