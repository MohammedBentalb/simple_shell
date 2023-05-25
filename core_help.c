#include "shell.h"
/**
 * run - Function that execute a command
 * @j: collection of data
 * Return: exit the function
 */

void run(info *j)
{
	int st = 0;
	pid_t sub = fork();

	if (sub == -1)
	{
	goto letgo;
	}

	if (sub == 0 && execve(j->arg[0], j->arg, NULL) == -1)
		goto letgo;
	else if (wait(&st) == -1)
		goto letgo;

	if (WIFEXITED(st))
	{
	j->status = WEXITSTATUS(st);
	}
return;
letgo:
	perror(j->name);
	arr_free(j->arg);
	free(j->cmd);
	exit(EXIT_FAILURE);
}
/**
 * _locate - Function that locate executable file
 * @j: collection of data
 * Return: status
 */
int _locate(info *j)
{
	size_t ln_s;
	char *lanes = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	int status = -1;
	char *symbol, *lane;

	if (!_getenv("PATH"))
		goto letgo;
	_strcpy(lanes, _getenv("PATH"));
	if (lanes == NULL)
		goto letgo;
	symbol = strtok(lanes, ":");
	while (symbol)
	{
	ln_s = _strlen(symbol) + _strlen(j->arg[0]) + 2;
	lane = malloc(ln_s);
		if (lane == NULL)
			return (status);
	_strcpy(lane, symbol);
	_strcat(lane, "/");
	_strcat(lane, j->arg[0]);
	if (access(lane, F_OK) == 0)
	{
		free(j->arg[0]);
		j->arg[0] = _strdup(lane);
		free(lane);
		status = 0;
		break;
	}
	free(lane);
	symbol = strtok(NULL, ":");
	}
letgo:
	free(lanes);
	return (status);
}

/**
 * _cut - Function that takes off spaces tabs from strings
 * @c: string input
 */

void _cut(char *c)
{
	int i, j, ln;

	ln = _strlen(c);
	for (i = 0; i < ln && (c[i] == ' ' || c[i] == '\t'); i++)
		;

	for (j = 0; i < ln ; i++, j++)
		c[j] = c[i];
	c[j] = '\0';

	ln = _strlen(c);
	i = ln - 1;
	while (i > 0 && (c[i] == ' ' || c[i] == '\t'))
	{
		c[i] = '\0';
		i--;
	}
}

/**
 * chop - Function that split strings
 * @j: collection of dats
 * @str: pointer
 */
void chop(info *j, const char *str)
{
	int symbol_n = 0;
	char *symbol;

	j->arg = malloc(2 * sizeof(char *));
	if (j->arg == NULL)
	{
	free(j->cmd);
	perror(j->name);
	exit(EXIT_FAILURE);
	}
	j->arg[0] = NULL;
	j->arg[1] = NULL;

	symbol = strtok(j->cmd, str);
	while (symbol != NULL)
	{
	j->arg = _realloc(j->arg, (symbol_n + 2) * sizeof(char *));
	if (j->arg == NULL)
		goto letgo;
	j->arg[symbol_n] = _strdup(symbol);
	if (j->arg[symbol_n] == NULL)
		goto letgo;
	symbol_n++;
	symbol = strtok(NULL, str);
	}
	j->arg[symbol_n] = NULL;
return;
letgo:
	arr_free(j->arg);
	free(j->cmd);
	perror(j->name);
	exit(EXIT_FAILURE);
}

/**
 * _read - Function that reads commend from cmd
 * @j: collection of data
 */
void _read(info *j)
{
	size_t size = 0;
	ssize_t get_s;
	int counter = 0;

	get_s = _getline(&j->cmd, &size, stdin);

	if (get_s == -1)
	{
		free(j->cmd);
		exit(EXIT_SUCCESS);
	}

	j->cmd[get_s - 1] = '\0';
	_cut(j->cmd);
	for (counter = 0; j->cmd[counter] != '\0'; counter++)
	{
		if (j->cmd[counter] == '#')
		{
			j->cmd[counter] = '\0';
			break;
		}
	}
_cut(j->cmd);
}
