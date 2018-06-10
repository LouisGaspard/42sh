/*
** EPITECH PROJECT, 2018
** cd
** File description:
** ...
*/

#include "42sh.h"

char	*my_search_home(char **env)
{
	int	a = 0;

	while (env[a]) {
		if (strncmp("HOME=", env[a], 5) == 0)
			return (env[a] + 5);
		a++;
	}
	return (NULL);
}

int    do_cd(char **command, t_shell *sh)
{
	sh->r_value = 0;
	if (chdir(command[1]) == -1) {
		sh->r_value = 1;
		if (access(command[1], F_OK) == -1)
			fprintf(stderr, "%s%s", command[1], ERR_ACCESS);
		else
			fprintf(stderr, "%s%s", command[1], ERR_DIR);
	}
	return (sh->r_value);
}

int	my_cd(t_shell *sh, char **command)
{
	int     i = 0;

	if (command[1] == NULL && my_search_home(sh->env) == NULL) {
		fprintf(stderr, "%s%s", command[0], ERR_HOME);
		return (sh->r_value = 1);
	}
	if (command[1] == NULL) {
		chdir(my_search_home(sh->env));
	} else if (command[1][0] == '-' && strlen(command[1]) == 1) {
		while (sh->env[i] && strncmp(sh->env[i], "OLDPWD=", 7) != 0)
			i++;
		if (!(sh->env[i]))
			return (1);
		chdir(sh->env[i] + 7);
	} else
		do_cd(command, sh);
	old_pwd(sh);
	maj_pwd(sh);
	return (sh->r_value);
}
