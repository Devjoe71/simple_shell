#include "our_headerfiles.h"
/**
 * input_from_user - a func that take input from the user
 * @cmd: this is the command from the user (string)
 *  @n: length/size of the sting
 *  Return: it returns nothing since it's a void
 *
 */

void input_from_user(char *cmd, size_t n)
{
	if (fgets(cmd, n, stdin) == NULL)
	{
		if (feof(stdin))
		{
			our_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			our_printf("Error occured while reading input \n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}
