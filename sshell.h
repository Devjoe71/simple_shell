#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_ARGS 150

void printout(const char *message);
/*void command_executer(const char *cmd);*/
void commandline(char *input, char *args[]);
void pathfinder(char *arguments[]);

#endif
