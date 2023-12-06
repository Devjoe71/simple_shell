
#include "sshell.h"
#include <stddef.h>
/**
 * command_executer - function that executes the commands
 * @cmd: pointer
 * Return: nothing since it's void
 */

void command_executer(const char *cmd)
{
	pid_t process_id = fork();
	char *args[MAX_ARGS];
	int x;

	if (process_id == 0)
	{
		int arg = 1;
		char *tkn = strtok((char *)cmd, " ");

		while (tkn != NULL)
		{
			tkn = strtok(NULL, " ");
			arg++;
		}

		args[0] = (char *)cmd;
		tkn = strtok((char *)cmd, " ");

		for (x = 1; x < arg; x++)
		{
			args[x] = tkn;
			tkn = strtok(NULL, " ");
		}

		args[arg] = NULL;
		execve(args[0], args, NULL);
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
