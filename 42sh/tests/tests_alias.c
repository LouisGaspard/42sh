/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu env
*/

#include "42sh.h"
#include <criterion/criterion.h>

t_shell	init_struct_tests(t_shell shell);

Test(my_alias, test_my_alias)
{
	t_shell	shell;
	int	value_ret = 0;
	char	**tab = malloc(sizeof(char *) * 3);

	shell = init_struct_tests(shell);
	tab[0] = strdup("alias");
	tab[1] = NULL;
	tab[2] = NULL;
	value_ret = my_alias(&shell, tab);
	cr_assert_eq(value_ret, 0);
	tab[0] = strdup("alias");
	tab[1] = strdup("ne");
	tab[2] = NULL;
	value_ret = my_alias(&shell, tab);
	cr_assert_eq(value_ret, 0);
	tab[0] = strdup("alias");
	tab[1] = strdup("ne");
	tab[2] = strdup("emacs");
	value_ret = my_alias(&shell, tab);
	cr_assert_eq(value_ret, 0);
}
