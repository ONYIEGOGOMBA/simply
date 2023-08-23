#include "shell.h"
#define MAX_ARGS 10
/**
 * parseArguments- a function that splits the
 * input into an array of arguments.
 * @input: function input.
 * @args:arguments.
 */
void parseArguments(char *input, char **args)
{
	char *token = strtok(input, " ");
	int i = 0;
	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
