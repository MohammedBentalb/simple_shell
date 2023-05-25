#include "shell.h"

/**
 * handle_cd - change directory
 * @j: collection of data
 */
void handle_cd(info *j)
{
	char *lane = j->arg[1];
	char crr_lane[256];

	if (getcwd(crr_lane, sizeof(crr_lane)) == NULL)
		perror("getcwd() error");
	_setenv(j, "PWD", crr_lane);
	if (!lane)
		lane = _getenv("HOME");
	if (chdir(lane) == -1)
		perror("cd");
	else
	{
		_setenv(j, "OLDPWD", _getenv("PWD"));
		if (getcwd(crr_lane, sizeof(crr_lane)) == NULL)
		perror("getcwd() error");
		_setenv(j, "PWD", crr_lane);
	}
}

/**
 * handle_exit - Function that handles exit
 * @j: collection of data
 */
void handle_exit(info *j)
{
	if (j->arg[1] && _isnumber(j->arg[1]))
		j->status = atoi(j->arg[1]);
	arr_free(j->arg);
	free(j->cmd);
	if (j->st)
		arr_free(environ);
exit(j->status);
}

/**
 * handle_env - Function that prints env
 * @j: collection of data
 */
void handle_env(info *j)
{
	int i = 0;

	(void)j;
	while (environ[i])
	{
		_write(environ[i]);
		_write("\n");
		i++;
	}
}
/**
 * handle_stenv - Function that set new env
 * @j: collection of data
 */

void handle_stenv(info *j)
{
	(void)j;
	if (j->arg[1] && j->arg[2])
	{
		if (_setenv(j, j->arg[1], j->arg[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * handle_unstenv - Function that remove env
 * @j: collection of data
 */
void handle_unstenv(info *j)
{
	int count, n;
	int ln;

	(void)j;
	if (!j->arg[1] || !getenv(j->arg[1]))
	{
		_perror(j->name, "variable not found.");
		return;
	}
	ln = strlen(j->arg[1]);
	for (count = 0; environ[count]; count++)
	{
		if (strncmp(environ[count], j->arg[1], ln) == 0 && environ[count][ln] == '=')
		{
			for (n = count; environ[n]; n++)
				environ[n] = environ[n + 1];
		}
	}
}
