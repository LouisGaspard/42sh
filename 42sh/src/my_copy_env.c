/*
** EPITECH PROJECT, 2018
** copy_env
** File description:
** copy_env
*/

#include "42sh.h"

int	count_line(char **env)
{
	int	a = 0;

	if (env == NULL)
		return (0);
	while (env[a])
		a++;
	return (a);
}

char	**copy_env(char **env)
{
	char	**new_env;
	int	nb_line = count_line(env);

	new_env = malloc(sizeof(char *) * (nb_line + 1));
	if (new_env == NULL)
		return (NULL);
	for (int a = 0; env[a]; a++)
		new_env[a] = strdup(env[a]);
	new_env[nb_line] = NULL;
	return (new_env);
}
