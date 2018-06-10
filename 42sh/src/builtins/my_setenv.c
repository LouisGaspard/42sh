/*
** EPITECH PROJECT, 2018
** myenv
** File description:
** ...
*/

#include "42sh.h"

int     my_char_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (0);
	else
		return (1);
}

int	my_env_loop(char **command, int i, char *var, t_shell *shell)
{
	int	len = strlen(var);

	while (shell->env[i]) {
		if (strncmp(shell->env[i], var, len) == 0 && !command[2]) {
			shell->env[i] = strdup(var);
			return (shell->r_value = 0);
		}
		if (strncmp(shell->env[i], var, len) == 0 && command[2]) {
			shell->env[i] = my_strcat(var, command[2]);
			return (shell->r_value = 0);
		}
		i++;
	}
	if (command[2] == NULL)
		shell->env = realloc_my_env(shell->env, var, NULL);
	if (command[2] != NULL)
		shell->env = realloc_my_env(shell->env, var, command[2]);
	free(var);
	return (shell->r_value = 0);
}

int	my_setenv(t_shell *shell, char **command)
{
	char    *var;
	int     i = 0;

	if (command[1] == NULL) {
		my_show_word_array(shell->env);
		return (shell->r_value = 0);
	}
	if (command[1])
		var = my_strcat(command[1], "=");
	if (my_str_isalphanum(command[1]) == 1) {
		fprintf(stderr, "%s%s%s", command[0], ERR_SETENV_CHAR, ERR_SET);
		return (shell->r_value = 1);
	}
	if (my_char_isalpha(var[0]) == 1) {
		fprintf(stderr, "%s%s", command[0], ERR_SETENV_NAME);
		return (shell->r_value = 1);
	}
	return (my_env_loop(command, i, var, shell));
}
