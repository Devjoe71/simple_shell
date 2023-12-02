#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void our_printf(const char *content, ...);
void prompt(void);
void input_from_user(char *cmd, size_t n);
void command_executer(const char *input);
int parse_command_line(void);
#endif
