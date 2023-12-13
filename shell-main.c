#include "shell.h"
/**
 * main - entry point
 * Return: zero
 */
int main(void)
{
	char input[100];

	while (1)
	{
		myprompt();
		user_input(input, sizeof(input));
		exec_cmd(input);
	}
	return (0);
}
