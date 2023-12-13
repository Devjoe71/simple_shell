#include "shell.h"
/**
 * user_input - func that takes user input
 * @input: user input/commands
 */
void user_input(char **input)
{
	size_t bufsize = 0;

	if (getline(input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			printout("\n");
			free(*input);
			*input = NULL;
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
