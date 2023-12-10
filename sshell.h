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
#include <stdarg.h>

#define MAX_ARGS 150
#define MAX_ARGMNTS_SZ 150
#define MAX_INPUT_SIZE 1024
void printout(const char *message, ...);
void command_executer(const char *cmd);
void commandline(char *input, char *args[]);
void pathfinder(char *arguments[]);
void handles_path(char *user_command);
void exit_the_shell(char *args[]);
void Environment(void);
extern char **environ;


#endif
