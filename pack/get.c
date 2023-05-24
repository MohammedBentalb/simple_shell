#include "shell.h"

/**
* *_getenv - Function that funtion the same as getenv
* @name: env
* Return: Return NULL || string
*/

char *_getenv(const char *name)
{

	char **env = environ;
	size_t name_len = _strlen(name);

	while (*env)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (*env + name_len + 1);
	env++;
	}
return (NULL);
}
