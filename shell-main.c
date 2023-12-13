#include "shell.h"
/**
 * main - entry point
 * Return: zero
 */
int main(void)
{
	char *input = NULL;

	while (1)
	{
		myprompt();
		user_input(&input);
		if (input == NULL)
			break;
		exec_cmd(input);
	}
	return (0);
}
