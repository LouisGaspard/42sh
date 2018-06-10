/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu cd
*/

#include "42sh.h"
#include <criterion/criterion.h>

t_shell	init_struct_tests(t_shell shell)
{
	shell = init_struct_null(shell);
	shell.env = create_env();
	return (shell);
}

Test(verif_cd, test_verif_cd)
{
	t_shell shell;
	int	value_ret = 0;
	char	**tab = malloc(sizeof(char *) * 3);

	shell = init_struct_tests(shell);
	tab[0] = strdup("cd");
	tab[1] = NULL;
	tab[2] = NULL;
	value_ret = my_cd(&shell, tab);
	cr_assert_eq(value_ret, 1);
	tab[0] = strdup("cd");
	tab[1] = strdup("-");
	tab[2] = NULL;
	value_ret = my_cd(&shell, tab);
	cr_assert_eq(value_ret, 1);
	tab[0] = strdup("cd");
	tab[1] = strdup("../src");
	tab[2] = NULL;
	value_ret = my_cd(&shell, tab);
	cr_assert_eq(value_ret, 1);
}
