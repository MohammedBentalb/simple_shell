#include "shell.h"

/**
 * handler - Function that containes handlers
 * @j: collection of data
 * Return: 1 if built in, 0 if not
 */
int handler(info *j)
{
	handle container[] = {
		{"exit", handle_exit}, {"env", handle_env},
		{"setenv", handle_stenv}, {"unsetenv", handle_unstenv},
		{"cd", handle_cd}, {NULL, NULL},
	};
	int i = 0;

	for (i = 0; container[i].c; i++)
	{
	if (_strcmp(j->arg[0], container[i].c) == 0)
	{
		container[i].f(j);
		return (1);
	}
	}
return (0);
}
