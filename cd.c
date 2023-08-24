#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
/**
 * print_error - prints the msg
 * main - entry point
 * @msg: The printed message
 * Return: returns 1
 */

void print_error(const char *msg)
{
	perror(msg);
}
/**
 * change_directory - entry point
 * @new_dir: The character
 * Return: Returns 1
 */
int change_directory(char *new_dir)
{
	if (chdir(new_dir) != 0)
	{
		print_error("chdir");
		return (1);
	}
	return (0);
}
/**
 * update_pwd - entry point
 * Return: Returns 0
 */
int update_pwd(void)
{
	char *current_dir = getcwd(NULL, 0);

	if (!current_dir || setenv("PWD", current_dir, 1) != 0)
	{
		print_error("setenv");
		free(current_dir);
		return (1);
	}
	free(current_dir);
	return (0);
}
/**
 * main - prints current_dir
 * @argc: The integer
 * @argv: the character
 * Return: returns 1
 */
int main(int argc, char *argv[])
{
	char *new_dir, *old_dir;

	old_dir = getcwd(NULL, 0);

	if (argc == 1)
		new_dir = getenv("HOME");
	else if (argc == 2)
		new_dir = strcmp(argv[1], "-") == 0 ? getenv("OLDPWD") : argv[1];

	else
	{
		print_error("Usage: cd [DIRECTORY]");
		return (1);
	}
	if (change_directory(new_dir) != 0 || update_pwd() != 0)
	{
		free(old_dir);
		return (1);
	}
	free(old_dir);
	return (0);
}
