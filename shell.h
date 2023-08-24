#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

void parseArguments(char *input, char **args);
void display_prompt(char **user_input, size_t *input_size);
void execute_prompt(char *command);


#endif
