#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES*/
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*PROTOTYPES*/
void myprompt(void);
void user_input(char **input, size_t bufsize);
char **split_line(const char *input);
char **exec_path(const char *execute);
void command_args(const char *input);
void exec_cmd(const char *input);
void printout(const char *input);
#endif
