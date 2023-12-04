#include "sshell.h"
/**
 * exit_the_shell - function that exits the shell
 * @args: pointer to arguments
 */

void exit_the_shell(char *args[])
{
	pid_t process_id = fork();

	if (process_id == 0)
	{
		char *env[] = {NULL};

		execve(args[0], args, env);
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
