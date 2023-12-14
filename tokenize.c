#include "shell.h"

/**
 * split_line - func that tokenize a string into array of string
 * @input: string to be tokenized
 * Return: string array
 */

char **split_line(const char *input)
{
	int buffer_size = 100;
	char **tkns = malloc(buffer_size * sizeof(char *));
	char *tkn;
	int index = 0;

	if (!tkns)
	{
		perror("failed to allocate memory: Malloc");
		exit(EXIT_FAILURE);
	}

	tkn = strtok((char *)input, " ");

	while (tkn != NULL)
	{
		tkns[index] = strdup(tkn);

		if (!tkns[index])
		{
			perror("failed to duplicate: strdup");
			exit(EXIT_FAILURE);
		}
		index++;

		if (index >= buffer_size)
		{
			buffer_size += 100;
			tkns = realloc(tkns, buffer_size * sizeof(char *));

			if (!tkns)
			{
				perror("failed to realloc");
				exit(EXIT_FAILURE);
			}
		}
		tkn = strtok(NULL, " ");
	}
	tkns[index] = NULL;
	return (tkns);
}
