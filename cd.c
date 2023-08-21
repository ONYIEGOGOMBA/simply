#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
/**
 * print_error - prints the msg
 * main - code function
 * Return: returns 1
 */

void print_error(const char *msg)
{
	perror(msg);
}
int main(int argc, char *argv[])
{
	char *new_dir;
	char *current_dir = getcwd(NULL, 0);
	char *old_dir = getcwd (NULL, 0);

	if (argc == 1)
	{
		new_dir = getenv("HOME");
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "-") == 0)
		{
			new_dir = getenv("OLDPWD");
		}
		else
		{
			new_dir = argv[1];
		}
	}
	else
	{
		print_error("Usage: cd [DIRECTORY]");
		return (1);
	}

	if (old_dir == NULL)
	{
		print_error("getcwd");
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		print_error("chdir");
		free(old_dir);
		return (1);
	}
	if (setenv("OLDPWD", old_dir, 1) != 0)
	{
		print_error("setenv");
		free(old_dir);
		return (1);
	}

	if (current_dir == NULL)
	{
		print_error("getcwd");
		free(old_dir);
		return (1);
	}

	if (setenv("PWD", current_dir, 1) != 0)
	{
		print_error("sentenv");
		free(old_dir);
		free(current_dir);
		return (1);
	}
	free(old_dir);
	free(current_dir);
	return (0);
}
