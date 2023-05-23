#include "shell.h"

/**
* find_executable - Function that finds a command
* @cmd: cmd
* @paths: the paths
* @path: path
* Return: Return 0 || 1
*/

int find_executable(char *cmd, char *path, char **paths)
{
	struct stat st;

	if (_strchr(cmd, '/') != NULL)
	{
	if (_stat(cmd, &st) == 0 && _S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
	{
	_strcpy(path, cmd);
	return (1);
	}
	}
	else
	{
	for (int i = 0; paths[i] != NULL; i++)
	{
	_strcpy(path, paths[i]);
	_strcat(path, "/");
	_strcat(path, cmd);
		if (_stat(path, &st) == 0 && _S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
		return (1);
		}
	}
	}
return (0);
}
