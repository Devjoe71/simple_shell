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
		char **args = (char **)malloc(sizeof(char *) * 2);
		
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		args[0] =strdup(input);

		if  (args[0] == NULL)
		{
			perror("stdup");
			exit(EXIT_FAILURE);
		}
		args[1] = NULL;
		execvp(input,args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
