/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** echo
*/

#include "42sh.h"

void	check_var_env(char *str, char *str2, int len, t_shell *shell)
{
	strcat(str, "=");
	len++;
	for (int j = 1; shell->env[j]; j++) {
		if (!strncmp(str, shell->env[j], len) && str2 == NULL) {
			printf("%s\n", shell->env[j] + len);
			return;
		}
		else if (!strncmp(str, shell->env[j], len) && str2 != NULL) {
			printf("%s ", shell->env[j] + len);
			return;
		}
	}
	printf("\n");
}

int	echo_in_env(t_shell *shell, char **command)
{
	int	len = 0;

	if (command[1][1] == '?') {
		printf("%d\n", shell->r_value);
		return (0);
	}
	for (int i = 1; command[i]; i++) {
		len = strlen(command[i] + 1);
		check_var_env(command[i] + 1, command[i + 1], len, shell);
	}
	return (0);
}

int	my_show_word_array_nl(char **command)
{
	for (int i = 2; command[i]; i++)
		printf("%s", command[i]);
	return (0);
}

int	my_echo(t_shell *shell, char **command)
{
	(void)shell;
	if (command[1][0] == '$') {
		echo_in_env(shell, command);
		return (0);
	}
	if (strcmp(command[1], "-n") == 0)
		return (my_show_word_array_nl(command));
	for (int i = 1; command[i]; i++) {
		if (command[i + 1] != NULL)
			printf("%s ", command[i]);
		else
			printf("%s\n", command[i]);
	}
	return (0);
}
