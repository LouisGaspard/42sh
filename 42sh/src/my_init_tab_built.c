/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "42sh.h"

char    **init_tab_built(void)
{
	char    **built;

	built = malloc(sizeof(char*) * 12);
	built[0] = strdup("cd");
	built[1] = strdup("setenv");
	built[2] = strdup("unsetenv");
	built[3] = strdup("env");
	built[4] = strdup("echo");
	built[5] = strdup("where");
	built[6] = strdup("which");
	built[7] = strdup("exit");
	built[8] = strdup("alias");
	built[9] = strdup("history");
	built[10] = strdup("repeat");
	built[11] = NULL;
	return (built);
}
