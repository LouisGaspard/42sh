/*
** EPITECH PROJECT, 2017
** aff_tab
** File description:
** aff_tab
*/

#include "42sh.h"

int	my_show_word_array(char * const *tab)
{
	int	a = 0;

	while (tab[a]) {
		printf("%s\n", tab[a]);
		a++;
	}
	return (1);
}
