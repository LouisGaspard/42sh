/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "42sh.h"
#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	(void)fd;
	read = getline(&line, &len, stdin);
	if (read == -1)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		line[i] = '\0';
	return (line);
}
