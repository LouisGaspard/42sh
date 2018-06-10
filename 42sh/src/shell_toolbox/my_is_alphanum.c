/*
** EPITECH PROJECT, 2017
** alphanum
** File description:
** alphanum
*/

int	my_is_alphanum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9') || c == '.'
		|| c == '_')
		return (0);
	else
		return (1);
	return (0);
}

int	my_is_alphanum2(char c)
{
	if (c == 124 || c == '>' || c == '<')
		return (1);
	else
		return (0);
	return (0);
}
