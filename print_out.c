#include "sshell.h"
/**
 * printout - this is our modified printf
 * @message: this is an input
 * Return: nothing
 */
void printout(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
