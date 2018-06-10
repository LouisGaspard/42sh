/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

char	*get_curr_dir(char **env)
{
	for (int i = 0; env[i]; i++)
		if (strncmp(env[i], "PWD=", 4) == 0)
			return (env[i] + 4);
	return (NULL);
}

char	*get_curr_name(char **env)
{
	for (int i = 0; env[i]; i++)
		if (strncmp(env[i], "USER=", 5) == 0)
			return (env[i] + 5);
	return ("user");
}
