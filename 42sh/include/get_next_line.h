/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** ...
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#ifndef SIZE_BUFFER
# define SIZE_BUFFER 1
#endif

char	*get_next_line(int fd);
