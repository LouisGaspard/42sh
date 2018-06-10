/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

t_shell	init_struct_null(t_shell shell)
{
	shell.user_name = NULL;
	shell.directory = NULL;
	shell.save_path = NULL;
	shell.command = NULL;
	shell.separator = NULL;
	shell.tab_path = NULL;
	shell.str = NULL;
	shell.pipe = NULL;
	shell.r_value = 0;
	shell.built = init_tab_built();
	init_base_cmd(shell.tab_cmd);
	shell.ali.name = NULL;
	shell.ali.command = NULL;
	return (shell);
}
