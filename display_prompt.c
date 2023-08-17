#include "shell.h"
#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10
/**
 * display_prompt- a function that displays a prompt.
 * @input:argument.
 */
void display_prompt(char *input)
{
	pid_t child_pid = fork();
	char *args[MAX_ARGS];

	parseArguments(input, args);

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *args[2];

		args[0] = input;
		args[1] = NULL;
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
