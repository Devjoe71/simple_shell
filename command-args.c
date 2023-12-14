#include "shell.h"
/**
 * command_args - func that execute command with arguments
 * @input: arguments
 */

void command_args(const char *input)
{
	char **args = split_line(input);
	pid_t process_id;
	char **fll_path_args = exec_path(args[0]);

	process_id = fork();


	if (access(args[0], F_OK) == -1)
	{
		printout(args[0]);
		perror(args[0]);
		free(args);
		return;
	}
	if (process_id == -1)
	{
		perror("Error occured during forking");
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		if (execve(fll_path_args[0], fll_path_args, NULL)  == -1)
		{
			perror(fll_path_args[0]);
			free(fll_path_args);
			free(args);
			exit(EXIT_FAILURE);
		}
		free(fll_path_args);
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
		free(args);
	}
}
