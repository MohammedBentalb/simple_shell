#include "shell.h"
/**
 * prbk - Function prints the text given
 * @arr: set of strings
 * Return: Returns 1 || -1
 */

int prbk(char *arr[])
{
	int i = 1;

	if (arr[i] == NULL)
	{
		write(1, "\n", 2);
		return (1);
	}

	while (arr[i] != NULL)
	{
		write(1, arr[i], _strlen(arr[i]));
		i++;
	if (arr[i] != NULL)
		write(1, " ", 2);
	}
	write(1, "\n", 2);

return (1);
}
