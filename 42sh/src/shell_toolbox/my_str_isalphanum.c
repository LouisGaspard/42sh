/*
** EPITECH PROJECT, 2018
** strisalpahnum
** File description:
** ...
*/

#include "42sh.h"

int	my_str_isalphanum(char *str)
{
	int	i = 0;

	while (str[i]) {
		if (my_is_alphanum(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
