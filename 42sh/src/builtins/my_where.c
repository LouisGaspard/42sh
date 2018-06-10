/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"
#include "get_next_line.h"

void	where_loop(char **tab, char **tab_path, int i)
{
	char    *file[2];

	file[1] = NULL;
	for (int y = 0; (tab_path[y]); y++) {
		file[0] = my_strcat(tab_path[y], "/");
		file[0] = my_strcat(file[0], tab[i]);
		if (!access(file[0], X_OK || F_OK))
			printf("%s/%s\n", tab_path[y], tab[i]);
	}
}

void	print_where_built(char **built, char **tab, int j)
{
	for (int i = 0; built[i]; i++) {
		if (strcmp(built[i], tab[j]) == 0)
			printf("%s is a shell built-in\n", tab[j]);
	}
}

int     my_where(t_shell *shell, char **tab)
{
	int	j = 1;

	if (!tab[1]) {
		fprintf(stderr, "where: Too few arguments.\n");
		return (shell->r_value = 1);
	}
	while (tab[j]) {
		print_where_built(shell->built, tab, j);
		where_loop(tab, shell->tab_path, j);
		j++;
	}
	return (0);
}
