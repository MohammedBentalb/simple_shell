#include "shell.h"
/**
* _getstr - Function that reads string from the cmd
* @str: pointer
* Return: return 1 || -1
*/

int _getstr(char *str)
{
	char **arr;
	size_t size = 0;

	signal(SIGINT, ctrc);
	arr = malloc(24);
	if (arr == NULL)
		return (-1);

	if ((getline(arr, &size, stdin)) == -1)
		return (-1);

	arr[0][size] = '\0';

	_strcpy(arr[0], str);

	if (arr[0][size - 2] == '\\')
	{
	while (arr[0][size - 2] == '\\')
	{
	str[_strlen(str) - 1] = ' ';
	size = 0;
	type_p(1);

	if ((getline(arr, &size, stdin)) == -1)
		return (-1);

	arr[0][size] = '\0';
	_strcat(arr[0], str);
	}
	}
	free(arr);
return (1);
}

/**
* _strcpy - Function that copys string
* @src: src
* @dest: dest
*/

void _strcpy(char *src, char *dest)
{
	int i = 0, j = 0;

	if (!dest)
		j = 0;

	while (src[i] != '\0' && src[i] != '\n')
		dest[j++] = src[i++];

dest[j] = '\0';
}

/**
* _strcat - Function that concatenates strings
* @src: src
* @dest: dest
*/

void _strcat(char *src, char *dest)
{
	int i = 0;
	int j = 0;

	if (!dest)
		j = 0;
	else
		j = _strlen(dest);

	while (src[i] != '\0' && src[i] != '\n')
		dest[j++] = src[i++];

dest[j] = '\0';
}

/**
* _strbr - Function break string
* @str: string
* @c: string
* Return: Return arr
*/

char **_strbr(char *str, char c)
{
	int i = 0, j = 0;
	char **arr, **temp;

	if (!str || str[0] == '\0')
		return (NULL);

	arr = malloc(sizeof(*arr) * 128);
	if (arr == NULL)
	{
		perror("could not allocate");
		return (NULL);
	}
	while (str[i] != '\0')
	{
	if (j > 124)
	{
	temp = realloc(arr, sizeof(*arr) * (i + 4));
	if (temp == NULL)
	{
		perror("could not reallocate");
		return (NULL);
	}
	else
		arr = temp;
	}
	if (str[i] == c)
	{
		i++;
		continue;
	}
	arr[j] = hlp_cat(str, i, arr[j], c);
	if (arr[j] == NULL)
		return (NULL);

	i += _strlen(arr[j++]);
	}
	arr[j] = NULL;
return (arr);
}

/**
* _strlen - Function that returns length
* @str: string
* Return: Returns ln
*/

int _strlen(char *str)
{
int ln = 0;

while (str[ln] != '\0')
{
ln++;
}

return (ln);
}

