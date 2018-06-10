/*
** EPITECH PROJECT, 2018
** pwd
** File description:
** ...
*/

#include "42sh.h"

void    old_pwd(t_shell *sh)
{
	char    *old;
	char    **maj = malloc(sizeof(char *) * 4);
	int     i = 0;

	if (!maj)
		return;
	while (sh->env[i] && strncmp(sh->env[i], "PWD=", 4) != 0)
		i++;
	if (sh->env[i] && strncmp(sh->env[i], "PWD=", 4) == 0)
		old = strdup(sh->env[i] + 4);
	maj[0] = strdup("setenv");
	maj[1] = strdup("OLDPWD");
	maj[2] = strdup(old);
	maj[3] = NULL;
	my_setenv(sh, maj);
	free_tab(maj);
	free(old);
}

void    maj_pwd(t_shell *sh)
{
	int     i = 0;
	char    **maj = malloc(sizeof(char *) * 4);
	char    pwd[1024];

	getcwd(pwd, sizeof(pwd));
	maj[0] = strdup("setenv");
	maj[1] = strdup("PWD");
	maj[2] = strdup(pwd);
	maj[3] = NULL;
	while (sh->env[i] && strncmp(sh->env[i], "PWD=", 4) != 0)
		i++;
	if (sh->env[i] && strncmp(sh->env[i], "PWD=", 4) == 0)
		my_setenv(sh, maj);
	free_tab(maj);
}
