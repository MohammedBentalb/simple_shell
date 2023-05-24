#include "shell.h"
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
/**
 * _strcmp - Function that compares between two strings
 * @str: first string
 * @st: secodn string
 * Return: Return res
 */

int _strcmp(char *str, char *st)
{
	int i = 0, res = 0;

	if (str == NULL || st == NULL)
		return (0);

	while (st[i] != '\0' || str[i] != '\0')
	{

	if (str[i] == st[i])
		res = 1;
	else
		res = 0;

	i++;
	}
return (res);
}
