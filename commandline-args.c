#include "sshell.h"

/**
 * commandline - func that execute command with arguments
 * @input: these are commands form user
 * @args: these are arguments
 * Returns: nothing
 */

void commandline(char *input, char *args[])
{
	pid_t process_id = fork();

	if (process_id  == 0)
	{
		execve(input, args, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (process_id > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Error");
	}
}
