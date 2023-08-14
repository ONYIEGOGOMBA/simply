#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt- a function that displays a prompt.
 * @command:argument.
 */

void display_prompt(char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		char *args[2];

		args[0] = (char *)command;
		args[1] = NULL;
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}

/**
 * main - main function.
 * void: doesn't take in arguments.
 * Return: 0.
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#simpleshell$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		display_prompt(command);
	}
	return (0);
}
