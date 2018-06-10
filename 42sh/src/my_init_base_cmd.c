/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

void    init_base_cmd(int (**tab_cmd)())
{
	tab_cmd[0] = my_cd;
	tab_cmd[1] = my_setenv;
	tab_cmd[2] = my_unsetenv;
	tab_cmd[3] = my_env;
	tab_cmd[4] = my_echo;
	tab_cmd[5] = my_where;
	tab_cmd[6] = my_which;
	tab_cmd[7] = my_exit;
	tab_cmd[8] = my_alias;
	tab_cmd[9] = my_history;
	tab_cmd[10] = my_repeat;
	tab_cmd[11] = 0;
}
