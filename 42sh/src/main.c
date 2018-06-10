/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	setbuf(stdout, NULL);
	if (env[0] == NULL)
		shell.env = create_env();
	else
		shell.env = copy_env(env);
	shell = init_struct_null(shell);
	shell.save_path = search_save(shell.env);
	shell.directory = get_curr_dir(shell.env);
	shell.user_name = get_curr_name(shell.env);
	my_shell(&shell);
	free_tab(shell.env);
	return (shell.r_value);
}
