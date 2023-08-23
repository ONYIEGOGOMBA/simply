#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_error - prints msg.
 * *msg - printed.
 * main - prints the commands.
 * Return: returns given command
 */
void print_error(const char *msg)
{
	perror(msg);
}

int main(command, variable, value, argc, argv)
	int argc;
	char *argv[];

	const char *command;
	const char *variable;
	const char *value;

{
	if (argc < 2)
	{
		print_error("Usage: ./env_commands setenv VARIABLE VALUE\n"
				" ./env_commands unsetenv VARIABLE");
		return (1);
	}
	command = argv[1];
	variable = argv[2];
	value = argv[3];

	if (strcmp(command, "setenv") == 0)
	{
		if (argc != 4)
		{
			print_error("Usage: ./env_commands setenv VARIABLE VALUE");
			return (1);
		}
		variable = argv[2];
		value = argv[3];

		if (setenv(variable, value, 1) != 0)
		{
			print_error("setenv");
			return (1);
		}
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		if (argc != 3)
		{
			print_error("Usage: ./env_commands unsetenv VARIABLE");
			return (1);
		}
		variable = argv[2];

		if (unsetenv(variable) != 0)
		{
			print_error("unsetenv");
			return (1);
		}
	}
	else
	{
		print_error("Unknown command");
		return (1);
	}
	return (0);
}
