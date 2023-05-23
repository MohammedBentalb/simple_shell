#include "shell.h"

/**
 * _strncmp - Function that compares n bytes of strings
 * @s1: first ctring
 * @s2: second string
 * @n: number of byte to compare
 * Return: 0 || defrence in ascii
 */


int _strncmp(const char *s1, const char *s2, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	if (s1[i] == '\0')
	{
		return (0);
	}
	}
return (0);
}

/**
 * _strcat - function that link two strings
 * @dest: dest
 * @src: src
 * Return: Return dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';
	return (dest);
}

/**
 * _atoi - Function that converts string to int
 * @s: string
 * Return: Return number
 */

int _atoi(char *s)
{
	int sign = 1, result = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s)
	{
	if (*s >= '0' && *s <= '9')
		result = (result * 10) + (*s - '0');
	else
		break;
	s++;
	}

return (result * sign);
}

