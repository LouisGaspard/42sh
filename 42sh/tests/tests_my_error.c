/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu_my_error
*/

#include "42sh.h"
#include <criterion/criterion.h>

Test(check_shlash, test_check_slash)
{
	int	value_ret = 0;
	char	*str = "toto";

	value_ret = check_slash(str);
	cr_assert_eq(value_ret, 0);
}

Test(is_dir, test_is_dir)
{
	int	value_ret = 0;
	char	*repo_name = "src";

	value_ret = is_dir(repo_name);
	cr_assert_eq(value_ret, 1);
}
