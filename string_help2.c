#include "shell.h"

/**
 * _strcat - acts like atrcat
 * @dest: dest
 * @src: src
 * Return: alt
 */
char *_strcat(char *dest, const char *src)
{
	char *alt = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
return (alt);
}

/**
 * _strdup - acts like strdup
 * @ptr: pointer
 * Return: Return result
 */
char *_strdup(const char *ptr)
{
	int count;
	int ln = 0;
	char *result;

	if (ptr == NULL)
	return (NULL);

	while (ptr[ln] != '\0')
		ln++;

	result = (char *)malloc((ln + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	count = 0;
	while (count <= ln)
	{
		result[count] = ptr[count];
		count++;
	}
return (result);
}
