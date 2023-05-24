#include "shell.h"
/**
 *  hlp_cat - Function that hepl string to break
 * @st: pointer
 * @n: index
 * @str: pointer
 * @c: character
 * Return: Returns str
 */

char *hlp_cat(char *st, int n, char *str, char c)
{
	int m = 0;
	char *temp;

	str = malloc(64);
	if (!str)
	{
		perror("Couldn't Allocate");
		return (NULL);
	}
	while (st[n] != c && st[n] != '\0')
	{
	str[m] = st[n++];
	m++;
	if (m > 60)
	{
	temp = realloc(str, (m + 8));
	if (!temp)
	{
	perror("Error");
	return (NULL);
	}
	else
	str = temp;
	}
	}
	str[m] = '\0';
return (str);
}

/**
 * maker - Function excutes the /bin/ls
 * @arr: set of strings
 * Return: returns 1|| -1
 */

int maker(char *arr[])
{
	int exit_stat;
	pid_t cr, sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");

	if (sub == 0)
	{
	execve("/bin/mkdir", arr, NULL);
	}
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
		perror("waiting...");
	}
	free(arr);
return (1);
}
