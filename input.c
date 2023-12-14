#include "shell.h"
/**
 * user_input - func that takes user input
 * @input: user input/commands
 * @bufsize: size of buffer
 */
void user_input(char **input, size_t bufsize)
{
	if (getline(input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			printout("\n");
			return;
		}
		else
		{
			perror("Error occured while getting input: getline");
			exit(EXIT_FAILURE);
		}
	}
	(*input)[strcspn(*input, "\n")] = '\0';
}
