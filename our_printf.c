#include "our_headerfiles.h"
/**
 * our_printf - function that allows us to print content instead of printf
 * @content:  This is what will be displayed
 * Return: nothing since it is void
 */
void our_printf(const char *content)
{
	write(STDOUT_FILENO, content, strlen(content));
}
