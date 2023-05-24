#include "shell.h"
/**
* exe_echo - Function give back whatever
* @arr: set or strings
* Return: returns 1 || -1
*/

int exe_echo(char *arr[])
{
	int exit_stat;
	pid_t cr, sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");
	if (sub == 0)
		execve("/bin/echo", arr, NULL);
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
		perror("waiting...");
	}
	free(arr);
return (1);
}

/**
* exe_ls - Function that lists using /bin/ls
* @arr: set of strings
* Return: Returns 1 || -1
*/

int exe_ls(char *arr[])
{
	int exit_stat;
	pid_t cr, sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");

	if (sub == 0)
		execve("/bin/ls", arr, NULL);
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
		perror("waiting...");
	}
	free(arr);

return (1);
}


/**
* exe_pwd - Function pwd
* @arr: set or strings
* Return: returns 1 || -1
*/

int exe_pwd(char *arr[])
{
	int exit_stat;
	pid_t cr;
	pid_t sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");

	if (sub == 0)
		execve("/bin/pwd", arr, NULL);
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
	perror("waiting...");
	}
	free(arr);
return (1);
}

/**
* exe_cat - Function that cat using /bin/cat
* @arr: set of strings
* Return: Returns 1 || -1
*/

int exe_cat(char *arr[])
{
	int exit_stat;
	pid_t cr, sub;

	sub = fork();
	if (sub == -1)
		perror("Forking");

	if (sub == 0)
		execve("/bin/cat", arr, NULL);
	else
	{
	cr = wait(&exit_stat);
	if (cr == -1)
		perror("waiting...");
	}
	free(arr);
return (1);
}

/**
* exe_cd - Function as cd
* @arr: ser of strings
* Return: Returns 0 || -1
*/

int exe_cd(char **arr)
{
	if (arr[1] == NULL)
		chdir(getenv("HOME"));
	else if (chdir(arr[1]) == -1)
	{
	write(1, arr[0], _strlen(arr[0]));
	write(1, ": ", 3);
	write(1, ": cd", _strlen(": cd"));
	write(1, ": cannot chdir to ", _strlen(": cannot chdir to "));
	write(1, arr[1], _strlen(arr[1]));
	write(1, "\n", 2);
	return (-1);
	}
	free(arr);
return (1);
}

