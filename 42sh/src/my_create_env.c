/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

char	**create_env(void)
{
	char	**tab = NULL;
	char	*path = malloc(sizeof(char) * ((1024 + 4) * 2));
	char	pwd[1024];

	getcwd(pwd, sizeof(pwd));
	path = my_strcat("PWD=", pwd);
	path = my_strcat(path, "\n");
	path = my_strcat(path, "OLDPWD=");
	path = my_strcat(path, pwd);
	path = my_strcat(path, "\nPATH=");
	path = my_strcat(path, "/usr/bin:/bin");
	path = my_strcat(path, "\nHOME=");
	path = my_strcat(path, "/");
	tab = my_str_to_word_array(path, "\n ");
	free(path);
	return (tab);
}
