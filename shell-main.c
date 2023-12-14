#include "shell.h"
/**
 * main - entry point
 * Return: zero
 */
int main(void)
{
	char *input = NULL;
	char **tkns;
	int x;
	char path[] = "/bin:/usr/bin:/usr/local/bin";

	setenv("PATH", path, 1);

	while (1)
	{
		char lspath[] = "/bin";
		char *cpath = getenv("PATH");
		char npath[1024];

		myprompt();
		user_input(&input, 0);

		if (input == NULL)
			break;

		snprintf(npath, sizeof(npath), "%s:%s", lspath, cpath);
		setenv("PATH", npath, 1);

		tkns = split_line(input);
		command_args(input);

		for (x = 0; tkns[x] != NULL; x++)
		{
			free(tkns[x]);
		}

		free(input);
		free(tkns);
	}
	return (0);
}
