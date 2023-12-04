#include "sshell.h"
/**
 * Environment - the func that prints the environment
 * Return: nothing
 */


void Environment(void)
{
	char **pointer = environ;

	while (*pointer != NULL)
	{
		printout("%s\n", *pointer);
		pointer++;
	}
}
