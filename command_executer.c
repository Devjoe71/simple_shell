#include "our_headerfiles.h"
#include <unistd.h>
#include <sys/wait.h>
/**
 * command_executer - this func executes inputs from user
 * @cmd: these are commands user types
 * Return: nothing since it's void
 */

void command_executer(const char *cmd)
{
	pid_t process_id = fork();

	if (process_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
