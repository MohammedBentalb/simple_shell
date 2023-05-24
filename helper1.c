#include "shell.h"
/**
 * cparr - Function that copies an array to an other arr
 * @str: string
 * Return: Return arr
 */

char **cparr(char **str)
{
	char **arr;
	int n = 1;

	arr = malloc(64);
	if (!arr)
		return (NULL);

	while (str[n] != NULL)
	{
	arr[(n - 1)] = malloc(32);
	if (!arr[(n - 1)])
		return (NULL);

	_strcpy(str[n], arr[(n - 1)]);
	n++;
	}

return (arr);
}

/**
 * ctrc - Function for handling ^c
 * @c: currently unused
 */

void ctrc(int c)
{
	(void) c;
	signal(SIGINT, ctrc);
	write(1, "\n", 2);
	type_p(0);
	fflush(stdout);
}

/**
* exe_un - Function to execute unhandeled command
* @arr: set of strings
* Return: Returns 0
*/

int exe_un(char **arr)
{
	int exit_stat;
	pid_t cr, sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");

	if (sub == 0)
	{
	execve(arr[0], arr, NULL);
	if (errno != 0)
		return (errno);
	}
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
	perror("Waiting...");
	}
	free(arr);
return (0);
}
/**
* type_p - Function write the entry character
* @i: int
*/

void type_p(int i)
{
	if (i == 0)
		write(1, "USH$ ", _strlen("USH$ "));
	else if (i == 1)
		write(1, "ush> ", _strlen("ush> "));

}
