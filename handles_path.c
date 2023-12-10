#include "sshell.h"
/**
 * handles_path - this function handles path
 * @user_command: this is the input from the user
 * Return: nothing
 */

void handles_path(char *user_command)
{
	int stats, x = 0;
	pid_t process_id, wpid;
	char *argmnts[MAX_ARGMNTS_SZ];
	char *tkn = strtok(user_command, " ");
	char *pt;
	char *copy_pt;
	char *pt_tkn;


	while (tkn != NULL)
	{
		argmnts[x++] = tkn;
		tkn = strtok(NULL, " ");
	}
	/* this here terminates the array*/
	argmnts[x] = NULL;
	pt = getenv("PATH");
	copy_pt = strdup(pt);
	pt_tkn = strtok(copy_pt, ":");

	while (pt_tkn != NULL)
	{
		char *fl_path = malloc(strlen(pt_tkn) + strlen(argmnts[0]) + 2);
		if (fl_path == NULL)
		{
			perror("malloc");
			free(copy_pt);
			return;
		}

		sprintf(fl_path, "%s/%s", pt_tkn, argmnts[0]);

		if (access(fl_path, X_OK) == 0)
		{
			process_id = fork();

			if (process_id == 0)
			{
				execve(fl_path, argmnts, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else if (process_id < 0)
			{
				perror("fork");
			}
			else
			{
				do {
					wpid = waitpid(process_id, &stats, WUNTRACED);
				} while (!WIFEXITED(stats) && !WIFSIGNALED(stats));

				if (wpid > 0)
					printout("child process %d completed\n", wpid);
				break;
			}
		}
		free(fl_path);
		pt_tkn = strtok(NULL, ":");
	}
	free(copy_pt);

	if (pt_tkn == NULL)
	{
		printout("command not found: %s\n", argmnts[0]);
	}
}
