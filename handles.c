#include "shell.h"

/**
* handle_exit - Function that handels exit
* @args: argument
*/
void handle_exit(char **args)
{
	(void) args;
	exit(0);
}

/**
* handle_cd - Function that handels cd
* @args: argument
*/

void handle_cd(char **args)
{
	if (args[1] == NULL)
	{
		chdir(_getenv("HOME"));
	}
	else if (_strcmp(args[1], "..") == 0)
	{
		chdir("..");
	}
	else
	{
		chdir(args[1]);
	}
}

/**
* handle_env - Function that handels env
* @args: argument
*/

void handle_env(char **args)
{
	(void) args;
	for (char **env = environ; *env; env++)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
* handle_clear - Function that handels clear
* @args: argument
*/

void handle_clear(char **args)
{
	(void) args;
	write(STDOUT_FILENO, "\033[2J\033[H", 7);
}
