#include "shell.h"

/**
 * getcmd - a function which selects a function based on the commands
 * @str: a command string pointer
 * Return: returns 1 in success and -1 if it fails.
 */

int (*getcmd(char *str))(char **arr)
{
	int i;
get_f container[] = {
{"ls", exe_ls},
{"cd", exe_cd},
{"l", exe_ls},
{"ll", exe_ls},
{"env", handle_env},
{"printenv", handle_env},
{"/bin/printenv", handle_env},
{"/bin/env", handle_env},
{"exit", handle_exit},
{"echo", exe_echo},
{"cat", exe_cat},
{"pwd", exe_pwd},
{"mkdir", maker},
{NULL, NULL}
};

	i = 0;
	while (!_strcmp(container[i].st, str) && (container[i].st != NULL))
		i++;

if (container[i].st == NULL)
	return (NULL);

return (container[i].f);
}

/**
 * execute - Function excutes commandds
 * @ptr: pointer
 * @args: arguments
 * Return: returns 1 || -1
 */

int execute(char **ptr, char **args)
{
	int vrf, i = 0;

	if (ptr == NULL)
		return (1);

	if (getcmd(ptr[0]) == NULL)
	{
		i = exe_un(ptr);
	if (i != 0)
	{
	for (i = 0; ptr[0][i] != '\0'; i++)
	{
	if (args[0][i] == '/')
	{
		vrf = 1;
		break;
	}
	}
	if (vrf == 1)
	{
		write(1, args[0], _strlen(args[0]));
		write(1, ": ", 3);
		write(1, ptr[0], _strlen(ptr[0]));
		write(1, ": No such file or directory\n", 28);
		exit(1);
	}
	else
	{
		write(1, ptr[0], _strlen(ptr[0]));
		write(1, ": not found\n", _strlen(": not found\n"));
		exit(1);
	}
	}
	}
	else
	{
	getcmd(ptr[0])(ptr);
	}
return (1);
}
