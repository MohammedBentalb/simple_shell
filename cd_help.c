#include "shell.h"

/**
 * _getenv - Functin that gets value of env var
 * @str: string
 * Return: environ
 */
char *_getenv(char *str)
{
	int counter;
	size_t ln;

	if (str == NULL || *str == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	ln = _strlen(str);

	for (counter = 0; environ[counter] != NULL; counter++)
	{
		if (!_strncmp(environ[counter], str, ln) && environ[counter][ln] == '=')
		{
		return (environ[counter] + ln + 1);
		}
	}
return (NULL);
}
/**
 * *set_ent - Helper function that ser new var
 * @ptr: pointer
 * @value: pointer to value
 * Return: en
 */
char *set_ent(char *ptr, char *value)
{
	size_t ln = _strlen(ptr) + _strlen(value) + 2;
	char *en = malloc(ln);

	if (en == NULL)
		return (NULL);

	strcpy(en, ptr);
	strcat(en, "=");
	strcat(en, value);
return (en);
}
/**
 * **nw_env - Funtion that set new env var
 * @ptr: pointer
 * @value: pointer to value
 * Return: n_envr
 */
char **nw_env(char *ptr, char *value)
{
	int ln = 0, counter = 0;
	char **new_env, *en;

	while (environ[ln])
		ln++;
	en = set_ent(ptr, value);
	if (en == NULL)
		return (NULL);
	new_env = _getenv(ptr) ? malloc((ln + 1) * sizeof(char *))
								: malloc((ln + 2) * sizeof(char *));
	if (!new_env)
	{
		free(en);
		return (NULL);
	}
	while (environ[counter])
	{
		new_env[counter] = malloc(strlen(environ[counter]) + 1);
		if (!new_env[counter])
		{
		arr_free(new_env);
		free(en);
		return (NULL);
		}
		if (strncmp(environ[counter], ptr, strlen(ptr)) == 0
		&& environ[counter][strlen(ptr)] == '=')
			strcpy(new_env[counter], en);
		else
			strcpy(new_env[counter], environ[counter]);
	counter++;
	}
	if (!_getenv(ptr))
	{
		new_env[ln] = en;
		new_env[ln + 1] = NULL;
	}
	else
		new_env[ln] = NULL;
	return (new_env);
}
/**
 * _setenv - Function that set env var
 * @j: to use the flag
 * @var: variable name
 * @value: variable value
 * Return: Return 1 || 0
 */
int _setenv(info *j, char *var, char *value)
{
	char **n_env;

	if (var == NULL || value == NULL)
		return (-1);

	n_env = nw_env(var, value);
	if (!n_env)
		return (-1);
	environ = n_env;
	j->st = 1;
return (0);
}
