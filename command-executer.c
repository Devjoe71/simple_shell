#include "shell.h"
/**
 * exec_cmd - func that executes command
 * @input: command from user
 */
void exec_cmd(const char *input)
{
	pid_t process_id = fork();

	if (process_id == -1)
	{
		perror("Error occured during forking");
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		command_args(input);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;

		waitpid(process_id, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			printout("successful\n");
		}
		else
		{
			printout("unsuccessful\n");
		}
	}
}
