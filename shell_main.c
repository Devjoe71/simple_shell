#include "sshell.h"
/**
 * main - this is our main entry point
 * Return: it returns zero
 */
int main(void)
{
	char *user_input = NULL;
	size_t size_of_input = 0;

	while (true)
	{
		printout("Simple_shell $");
		/*read the line of user input*/

		if (getline(&user_input, &size_of_input, stdin) == -1)
		{
			/*This will handle end of file (Ctrl + D)*/

			printout("\n");
			break;
		}
		/* we will remove trailing newline*/
		user_input[strcspn(user_input, "\n")] = '\0';
		command_executer("ls -l");
	}
	free(user_input);
	return (0);
}
