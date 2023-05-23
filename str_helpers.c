#include "shell.h"

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
return (0);
}

/**
 * _memset - Function that fills memory with aa value
 * @s: pointer
 * @c: value
 * @n: number of bytes to be filled
 * Return: Return s
 */

void *_memset(void *s, int c, size_t n)
{
	char *p = (char *)s;

	while (n-- > 0)
	{
		*p++ = (char)c;
	}
return (s);
}

/**
 * _strchr - Function that look for a character in a string
 * @s: string
 * @c: the character
 * Return: Return s || NULL
 */

char *_strchr(char *s, int c)
{
	while (*s != '\0')
	{
	if (*s == c)
	{
		return (s);
	}
	s++;
	}
return (NULL);
}

/**
 * _strlen - Function that returns the length of a string.
 * @s: The string to get the length of.
 * Return: The length of @s.
 */

int _strlen(const char *s)
{
	unsigned int len = 0;

	while (*s++)
	{
		len++;
	}
return (len);
}

/**
 * *_strcpy - Function that copies a string from src to dest
 * @dest: dest
 * @src: src
 * Return: Return dest
 */

char *_strcpy(char *dest, char *src)
{

	unsigned int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

return (dest);
}
