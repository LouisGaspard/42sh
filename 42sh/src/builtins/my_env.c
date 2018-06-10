/*
** EPITECH PROJECT, 2018
** myenv
** File description:
** ...
*/

#include "42sh.h"

int	my_env(t_shell *shell, char **command)
{
	(void)command;
	for (int i = 0; shell->env[i]; i++)
		printf("%s\n", shell->env[i]);
	return (0);
}
