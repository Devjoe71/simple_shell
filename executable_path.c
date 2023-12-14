#include "shell.h"

/**
 * exec_path - find full path
 * @execute: executable
 * Return: array of string
 */

char **exec_path(const char *execute)
{
	char **rslt = (char **)malloc(sizeof(char *) * 2);

	rslt[0] = strdup(execute);
	rslt[1] = NULL;
	return (rslt);
}
