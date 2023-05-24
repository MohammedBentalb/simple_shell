#include "shell.h"

/**
* handle_exit - Function thathandle exit command
* @arr: set of strings
* Return: exit
*/

int handle_exit(char *arr[])
{
	int i = 0;

	if (arr[1] == NULL)
		exit(EXIT_SUCCESS);
	else if (_atoi(arr[1]) > 0)
		i = _atoi(arr[1]);
	free(arr);
exit(i);
}

/**
 * handle_env - Function
 * @arr: pointer
 * Return: returns 1 || -1
 */

int handle_env(char *arr[] __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 2);
	i++;
	}
	free(arr);
return (1);
}
