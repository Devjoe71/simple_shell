#include "sshell.h"
/**
 * main - this is our main entry point
 * Return: it returns zero
 */
int main(void)
{
	char *args[MAX_ARGS];
	char *user_input = NULL;
	size_t size_of_input = 0;
	int i;
	int arg_count;
	char *tkn;

	while (1)
	{
		printout("Simple_shell $ ");
		/*read the line of user input*/

		if (getline(&user_input, &size_of_input, stdin) == -1)
		{
			/*This will handle end of file (Ctrl + D)*/

			printout("\n");
			break;
		}
		/* we will remove trailing newline*/
		user_input[strcspn(user_input, "\n")] = '\0';

		if (strcmp(user_input, "env") == 0)
		{
			Environment();
			continue;
		}
		command_executer("ls -l");
		/*tokenize user_input*/
		arg_count = 0;
		tkn = strtok(user_input, " ");

		while (tkn != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = strdup(tkn);
			tkn = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		if (arg_count > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				printout("exiting the shell\n");
				break;
			}
		exit_the_shell(args);
		commandline(args[0], args);
		pathfinder(args);
		}
		for (i = 0; i < arg_count; ++i)
		{
			free(args[i]);
		}
	}
	free(user_input);
	return (0);
}
