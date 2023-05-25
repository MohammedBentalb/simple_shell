#include "shell.h"
/**
 * _strcpy - acts like strcpy
 * @dest: dest
 * @src: src (const for savety)
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
	dest[count] = src[count];
	count++;
	}
	dest[count] = '\0';
	return (dest);
}

/**
 * _strncmp - acts like strncmp
 * @fst: first string
 * @sec: second string
 * @num: number
 * Return: Return result
 */
int _strncmp(const char *fst, const char *sec, int num)
{
	int count;
	int result;

	count = 0;
	result = 0;
	while (fst[count] != '\0' && sec[count] != '\0')
	{

		if (count >= num)
			break;
		if (fst[count] != sec[count])
		{
		result = fst[count] - sec[count];
		break;
		}
	count++;
	}

return (result);
}

/**
 * _strlen - acts like strlen
 * @s: string
 * Return: Return count
 */
unsigned int _strlen(char *s)
{
	unsigned int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
return (count);
}
/**
 * _strcmp - acts like strcmp
 * @sec: second string
 * @fst: first string
 * Return: Return result
 */
int _strcmp(const char *fst, const char *sec)
{
	int count;
	int result;

	count = 0;
	result = 0;
	while (fst[count] != '\0' && sec[count] != '\0')
	{
		if (fst[count] != sec[count])
		{
			result = fst[count] - sec[count];
			break;
		}
	count++;
	}

return (result);
}
