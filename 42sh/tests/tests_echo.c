/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu env
*/

#include "42sh.h"
#include <criterion/criterion.h>

t_shell	init_struct_tests(t_shell shell);

Test(my_echo, test_my_echo)
{
	t_shell	shell;
	int	value_ret = 0;
	char	**tab = malloc(sizeof(char *) * 4);

	shell = init_struct_tests(shell);
	tab[0] = strdup("echo");
	tab[1] = strdup("$HOME");
	tab[2] = NULL;
	value_ret = my_echo(&shell, tab);
	cr_assert_eq(value_ret, 0);
	tab[0] = strdup("echo");
	tab[1] = strdup("toto");
	tab[2] = NULL;
	value_ret = my_echo(&shell, tab);
	cr_assert_eq(value_ret, 0);
	tab[0] = strdup("echo");
	tab[1] = strdup("-n");
	tab[2] = strdup("coucou");
	tab[3] = NULL;
	value_ret = my_echo(&shell, tab);
	cr_assert_eq(value_ret, 0);
}
