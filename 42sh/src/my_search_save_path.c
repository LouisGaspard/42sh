/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

char    *search_save(char **tab)
{
	int     i = 0;

	while (tab[i] && strncmp(tab[i], "PATH=", 5))
		i++;
	if (tab[i] == NULL)
		return (strdup("PATH=/usr/bin:/bin"));
	return (strdup(tab[i] + 5));
}
