#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * print_error - it prints the msg
 * @msg: printed msg
 * Return: Returns num.
 */

void print_error(const char *msg)
{
	perror(msg);
}
/**
 * execute_command - it executes the given command.
 * @command: executed
 * Return: returns 1
 */
int execute_command(char *command)
{
	char *args[1024];
	int arg_count = 0;
	char *token = strtok(command, " \t\n");
	pid_t pid = fork();

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
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
 * execute_logical_operators - It handles logical operators
 * @commands: it handles individual command execution.
 * Return: It returns a succees message
 */
int execute_logical_operators(char *commands)
{
	int success = 1;
	char *command = strtok(commands, "&&\n");

	while (command != NULL)
	{
		int result = execute_command(command);

		if (strstr(command, "||"))
		{
			if (result != 0)
			{
				success = 0;
				break;
			}
		}
		else if (result != 0)
		{
			success = 0;
			break;
		}
		command = strtok(NULL, "&&\n");
	}
	return (success);
}
/**
 * main - prints the executed command
 * Return: Always 0
 */

int main(void)
{
	int success;
	char input[1024];

	printf("Shell> ");
	while (fgets(input, sizeof(input), stdin) != NULL)
	{
		int success = execute_logical_operators(input);
		}

		if (success)
		{
			printf("ALL commands succeeded.\n");
		}
		else
		{
			fprintf(stderr, "Some command(s) failed.\n");
		}
		printf("shell> ");
	}
	return (0);
}
