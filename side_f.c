#include "shell.h"

/**
 * _realloc - Function that allocates new mem
 * @p: pointer
 * @size: size
 * Return: Return new
 */
void *_realloc(void *p, unsigned int size)
{
	char *new;
	unsigned int count;
	unsigned int temp = size, prv = sizeof(p);

	if (prv == size)
		return (p);
	if (p == NULL)
		return (malloc(size));

	if (size > prv)
		temp = prv;

	if (size == 0)
	{
		free(p);
		return (NULL);
	}

	new = malloc(size);

	count = 0;
	while (count < temp)
	{
	new[count] = ((char *)p)[count];
	count++;
	}
free(p);
return (new);
}
/**
 * _write - print a string to stander out put
 * @s: string input
 * Return: void
 */
void _write(const char *s)
{
	if (!s)
		return;
	while (*s)
	{
		write(STDOUT_FILENO, s, 1);
		s++;
	}
}
/**
 * _perror - print in stderr
 * @name: name of shell program
 * @err: message
 * Return: exit function
 */
void _perror(const char *name, const char *err)
{
	unsigned int i;

	if (name == NULL || err == NULL)
		return;

	for (i = 0; name[i] != '\0'; i++)
	{
	write(STDERR_FILENO, &name[i], 1);
	}

	write(STDERR_FILENO, ": ", 2);

	i = 0;
	for (i = 0; err[i]; i++)
	{
	write(STDERR_FILENO, &err[i], 1);
	}
	write(STDERR_FILENO, "\n", 1);
}
/**
 * arr_free - Function that frees pointers
 * @arr: pointer
 */
void arr_free(char **arr)
{
	int counter;

	if (arr == NULL)
		return;

	for (counter = 0; arr[counter]; counter++)
	{
		free(arr[counter]);
		arr[counter] = NULL;
	}
free(arr);
}
