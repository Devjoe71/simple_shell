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
		perror("Error occured while fork");
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		char **arg = (char **)malloc(2 *sizeof(char *));

		if (arg == NULL)
		{
			perror("Malloc");
			exit(EXIT_FAILURE);
		}
		arg[0] =strdup(input);

		if (arg[0] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		arg[1] = NULL;

		if (execve(input, arg, NULL) == -1)
		{
			perror(input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(process_id, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			printout("successfully \n");
		}
		else
		{
			printout("unsuccessful \n");
		}
	}
}
