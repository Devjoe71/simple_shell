#include "our_headerfiles.h"
/**
 * main - this function acts as our entry point
 * Return: always zero
 */

int main(void)
{
	char cmd[150];

	while (1)
	{
		prompt();
		input_from_user(cmd, sizeof(cmd));
		command_executer(cmd);
		parse_command_line();
	}
	return (0);
}
