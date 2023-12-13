#include "shell.h"
/**
 * printout - func that prints the customised printf
 * @input: message from user
 */
void printout(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
