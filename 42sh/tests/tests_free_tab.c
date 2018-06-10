/*
** EPITECH PROJECT, 2017
** tests_get_input
** File description:
** tests_get_input
*/

#include "42sh.h"
#include <criterion/criterion.h>

Test(free_tab, check_free_tab)
{
	char	**tab = malloc(sizeof(char *) * 4);
	char	**tab1 = NULL;

	tab[0] = strdup("toto");
	tab[1] = strdup("tata");
	tab[2] = strdup("titi");
	tab[3] = NULL;
	cr_assert(free_tab(tab) == 0);
	cr_assert(free_tab(tab1) == 1);
}
