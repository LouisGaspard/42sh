/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu env
*/

#include "42sh.h"
#include <criterion/criterion.h>

t_shell	init_struct_tests(t_shell shell);

Test(my_repeat, test_my_repeat)
{
	t_shell	shell;
	int	value_ret = 0;
	char	**tab = malloc(sizeof(char *) * 4);

	shell = init_struct_tests(shell);
	tab[0] = strdup("repeat");
	tab[1] = NULL;
	tab[2] = NULL;
	tab[3] = NULL;
	value_ret = my_repeat(&shell, tab);
	cr_assert_eq(value_ret, 1);
	tab[0] = strdup("repeat");
	tab[1] = strdup("2");
	tab[2] = strdup("env");
	tab[3] = NULL;
	value_ret = my_repeat(&shell, tab);
	cr_assert_eq(value_ret, 0);
}
