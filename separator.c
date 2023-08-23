#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * print_error - prints msg
 * execute_command - It executes the command
 * Return: It returns 1
 */
void print_error(const char *msg)
{
	perror(msg);
}

int execute_command(char *command)
{
	char *args[1024];
	int arg_count = 0;
	char *token = strtok(command, "\t\n");
	pid_t pid = fork();

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, "\t\n");
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
	{
		return (0);
	}

	if (pid < 0)
	{
		print_error("fork");
		return (1);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		print_error("execvp");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (1);
		}
	}
}
/**
 * main - It has the function
 * Return: always 0
 */

int main(void)
{
	char input[1024];
	printf("Shell> ");
	while (fgets(input, sizeof(input), stdin) != NULL)
	{
		char *command = strtok(input, ";");
		while (command != NULL)
		{
			int result = execute_command(command);
			if (result != 0)
			{
				fprintf(stderr, "command failed: %s\n", command);
			}
			command = strtok(NULL, ";");
		}
		printf("Shell> ");
	}
	return (0);
}
