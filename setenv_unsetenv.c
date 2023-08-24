#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_error - prints msg.
 * @msg: printed message
 */
void print_error(const char char *msg)
{
	perror(msg);
}
/**
 * handle_setenv - calls the handler
 * @variable: a character
 * @value: a character
 * Return: always 0
 */
int handle_setenv(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		print_error("setenv");
		return (1);
	}
	return (0);
}
/**
 * handle_unsetenv - calls the handler
 * @variable: a character
 * Return: returns 0
 */
int handle_unsetenv(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		print_error("unsetenv");
		return (1);
	}
	return (0);
}
/**
 * main - starts the loop
 * @argc: integer
 * @argv: character
 * Return: returns a value
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_error("Usage: ./env_commands setenv VARIABLE VALUE\n"
				"./env_commands unsetenv VARIABLE");
		return (1);
	}
	const cahr *command = argv[1];

	if (strcmp(command, "setenv") == 0)
	{
		if (argc != 4)
		{
			print_error("Usage: ./env_commands unsetenv VARIABLE");
			return (1);
		}
		const char *variable = argv[2];

		const char *value = argv[3];

		return (handle_setenv(variable, value));
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		if (argc != 3)
		{
			print_error("Usage: ./env_commands unsetenv VARIABLE");
			return (1);
		}
		const char *variable = argv[2];

		return (handle_unsetenv(variable));
	}
	else
	{
		print_error("Unknown command");
		return (1);
	}
	return (0);
}
