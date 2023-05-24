#include "shell.h"
/**
 * _getchr - Function that reads a character
 * Return: Retunr c
 */

char _getchr(void)
{
	char *buffer, c;
	int n;

	buffer = malloc(2);

	if (buffer == NULL)
		return (-1);

	fflush(stdout);

	n = read(1, buffer, 1);
	if (n == -1)
	{
		perror("Reading Char");
		return (-1);
	}
	else if (n == 0)
	{
		write(1, "\n", 2);
		fflush(stdout);
	exit(1);
	}
	c = *buffer;
return (c);
}



/**
 * _getline - Function to read a line in stdout
 * @str: pointer
 * @ln: size of the characters that has been read
 * Return: Return ln
 */

int _getline(char **str, size_t *ln)
{
	size_t maxx = 25;
	char *temp;

	str[0] = malloc(25);
	if (!str[0])
		return (-1);
	*ln = 0;

	while (str[0][*ln - 1] != '\n')
	{
	str[0][*ln] = _getchr();
	*ln += 1;

	if (*ln > (maxx - 3))
	{
		temp = realloc(str[0], maxx + 10);
		if (temp)
			str[0] = temp;
		else
		perror("re-allocate");
		maxx = 10 + maxx;
	}
	}

return (*ln);
}
