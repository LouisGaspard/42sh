/*
** EPITECH PROJECT, 2018
** path
** File description:
** ...
*/

#include "42sh.h"

char    **search_path(char **tab)
{
	int     i = 0;

	while (tab[i] && strncmp(tab[i], "PATH=", 5))
		i++;
	if (tab[i] == NULL || tab[i][5] == '\0')
		return (NULL);
	return (my_str_to_word_array(tab[i] + 5, ":"));
}

int     file_exist(char **file, char **my_env, char **tab)
{
	int   i = 0;
	pid_t pid = 0;

	if (!access(file[0], X_OK || F_OK)) {
		pid = fork();
		if (pid == 0)
			execve(file[0], tab, my_env);
		waitpid(pid, &i, 0);
		return (1);
	}
	return (0);
}

char	*my_strcat_path(char *str1, char *str2)
{
	int	a = strlen(str1);
	int	b = strlen(str2);
	char	*dest = malloc(sizeof(char) * (a + b) + 2);

	if (dest == NULL)
		return (NULL);
	b = 0;
	for (a = 0; str1[a]; a++) {
		dest[b] = str1[a];
		b++;
	}
	dest[b] = '/';
	b++;
	for (a = 0; str2[a]; a++) {
		dest[b] = str2[a];
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

int     my_command(t_shell *shell, char **my_env, char **tab, char **tab_path)
{
	int   y = 0;
	char    *file[2];

	file[1] = NULL;
	if (check_if_i_have_slash(shell) == 1)
		return (1);
	if (tab_path == NULL) {
		fprintf(stderr, "%s%s", tab[0], ERR_NOT_FOUND);
		return ((shell->r_value = 1), 1);
	}
	while (tab_path[y]) {
		file[0] = my_strcat_path(tab_path[y], tab[0]);
		if ((file_exist(file, my_env, tab)) == 1) {
			free(file[0]);
			return (1);
		}
		y++;
	}
	fprintf(stderr, "%s%s", tab[0], ERR_NOT_FOUND);
	return ((shell->r_value = 1), 0);
}
