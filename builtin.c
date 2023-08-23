#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exit;

	if (info->argv[1])
	{
		exit = _erratoi(info->argv[1]);
		if (exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */

int _mycd(info_t *info)
{
	char *b, *dr, buffer[1024];
	int chdir_rent;

	b = getcwd(buffer, 1024);
	if (!b)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chdir_rent = chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chdir_rent = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(b);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_rent = chdir(info->argv[1]);
	if (chdir_rent == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **bog_mm;

	bog_mm = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*bog_mm);
	return (0);
}
