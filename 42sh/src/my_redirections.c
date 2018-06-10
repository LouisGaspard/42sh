/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** redirections
*/

#include "42sh.h"
#include "get_next_line.h"

void    remove_spaces(char *str)
{
	char	*i = str;
	char	*j = str;

	while (*j != 0) {
		*i = *j++;
		if (*i != ' ' && *i != '\t')
			i++;
	}
	*i = '\0';
}

void	count_red(t_red *red, char *cmd)
{
	int	i = 0;
	int	j = 0;

	while (cmd[i]) {
		if (strncmp(&cmd[i], "<<", 2) == 0) {
			red->type[j += 1] = 0;
			i++;
		} else if (cmd[i] == '<')
			red->type[j += 1] = 1;
		if (strncmp(&cmd[i], ">>", 2) == 0) {
			red->type[j += 1] = 2;
			i++;
		} else if (cmd[i] == '>')
			red->type[j += 1] = 3;
		i++;
	}
}

t_red   *parse_red(t_shell *shell, int count)
{
	t_red	*red = malloc(sizeof(*red));
	int	i = 1;

	if (red == NULL)
		return (NULL);
	red->cmd = my_str_to_word_array(shell->pipe[count], "><");
	if (red->cmd == NULL)
		return (NULL);
	for (i = 1; red->cmd[i] != NULL; i++)
		remove_spaces(red->cmd[i]);
	red->type = malloc(sizeof(int) * count_line(red->cmd));
	if (red->type == NULL)
		return (NULL);
	count_red(red, shell->pipe[count]);
	if (red->cmd[0] != NULL)
		shell->pipe[count] = strdup(red->cmd[0]);
	return (red);
}

int     get_fd_1(t_red *red)
{
	int	fd = 1;
	int	i = 1;

	if (red == NULL || red->cmd == NULL || red->cmd[0] == NULL)
		return (1);
	if (red->type == NULL)
		return (1);
	while (red->cmd[i]) {
		if ((red->type[i - 1] == 2 || red->type[i - 1] == 3) &&
			(fd = open(red->cmd[i], O_CREAT | O_WRONLY, 00666))
			!= -1)
			break;
		i++;
	}
	if (red->type[i - 1] == 2)
		lseek(fd, 0, SEEK_END);
	return (fd);
}

int     get_fd_0(t_red *red)
{
	int	fd = 0;
	int	i = 1;

	if (red == NULL || red->cmd == NULL || red->cmd[0] == NULL)
		return (0);
	if (red->type == NULL)
		return (0);
	while (red->cmd[i] && red->type[i - 1]) {
		if (red->type[i - 1] == 1
			&& (fd = open(red->cmd[i], O_RDONLY)) != -1)
			return (fd);
		i++;
	}
	return (0);
}
