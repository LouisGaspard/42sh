/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tu env
*/

#include "42sh.h"
#include <criterion/criterion.h>

Test(my_char_isalpha, test_my_char_isalpha)
{
	int	value_ret = 0;
	int	c = 'c';

	value_ret = my_char_isalpha(c);
	cr_assert_eq(value_ret, 0);
}
