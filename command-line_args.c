#include "our_headerfiles.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * parse_command_line - func that accepts command
 * Return: returns zero
 */

int parse_command_line(void)
{
	char *delim = " \n";
	size_t m = 0;
	int i = 0, argc = 0;
	char *command = NULL, **argv = NULL;
	char *cmd_copy = NULL, *tkn = NULL;

	if (getline(&command, &m, stdin) == -1)
		return (-1);
	cmd_copy = strdup(command);
	tkn = strtok(command, delim);
	while (tkn)
	{
		tkn = strtok(NULL, delim);
		argc++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	tkn = strtok(cmd_copy, delim);
	while (tkn)
	{
		argv[i] = strdup(tkn);
		tkn = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	for (i = 0; argv[i] != NULL; i++)
	{
		our_printf("argv[%d]: %s\n", i, argv[i]);
	}
	free(command);
	free(cmd_copy);
	for (i = 0; i < argc; i++)
	{
		free(argv[i]);
	}
	free(argv);
	return (0);
}
