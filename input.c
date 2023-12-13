#include "shell.h"
/**
 * user_input - func that takes user input
 * @input: user input/commands
 * @bufsize: size of the input
 */
void user_input(char *input, size_t bufsize)
{
	if (getline(&input, &bufsize, stdin) == -1)
	{
		perror("faild while getting user input");
		exit(EXIT_FAILURE);
	}
}
