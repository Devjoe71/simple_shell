#include "sshell.h"
/**
 *printout - this is our modified printf
 * @message: this is an input
 * @...: variable number of arguments
 * Return: nothing
 */
void printout(const char *message, ...)
{
	char buff[1024];
	int length;
	va_list args;


	va_start(args, message);

	length = vsnprintf(buff, sizeof(buff), message, args);
	va_end(args);

	if (length >= 0 && (size_t)length < sizeof(buff))
	{
		write(STDOUT_FILENO, buff, length);
	}
	else
	{
		write(STDOUT_FILENO, "Error when printing\n", 20);
	}
}
