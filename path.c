#include "sshell.h"

/**
 * pathfinder - funct that handles the path
 * @args: pointer
 * Return: nothing
 */

void pathfinder(char *args[])
{
	pid_t process_id = fork();

	if (process_id == 0)
	{
		char *env[] = {NULL};

		execve(args[0], args, env);
		perror("Error");
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
