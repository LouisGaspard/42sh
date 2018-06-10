/*
** EPITECH PROJECT, 2017
** tests_get_input
** File description:
** tests_get_input
*/

#include "42sh.h"
#include <criterion/criterion.h>

Test(count_line, check_count_line)
{
	char	**tab_4 = malloc(sizeof(char *) * 4);
	char	**tab_null = NULL;

	tab_4[0] = "toto";
	tab_4[1] = "tata";
	tab_4[2] = "titi";
	tab_4[3] = NULL;
	cr_assert(count_line(tab_4) == 3);
	cr_assert(count_line(tab_null) == 0);
}

Test(copy_env, check_copy_env)
{
	char	**tab1 = malloc(sizeof(char *) * 4);
	char	**tab2;

	tab1[0] = "toto";
	tab1[1] = "tata";
	tab1[2] = "titi";
	tab1[3] = NULL;
	tab2 = copy_env(tab1);
	cr_assert(strcmp(tab1[0], tab2[0]) == 0);
	cr_assert(strcmp(tab1[1], tab2[1]) == 0);
	cr_assert(strcmp(tab1[2], tab2[2]) == 0);
}
