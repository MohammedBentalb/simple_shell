#include "shell.h"
/**
* execute_command - Function that execute the command
* @args: arguments
* @paths: the paths
* @name: program name
*/
void execute_command(char **args, char *name, char **paths)
{
	char path[MAX_INPUT_SIZE];

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
		int exit_status = _atoi(args[1]);

		exit(exit_status);
		}
		handle_exit(args);
	}
	else if (_strcmp(args[0], "cd") == 0)
		handle_cd(args);
	else if (_strcmp(args[0], "clear") == 0)
	handle_clear(args);
	else if (_strcmp(args[0], "env") == 0)
		handle_env(args);
	else
	{
	if (find_executable(args[0], path, paths))
	{
		pid_t pid = fork();

		if (pid == 0)
		{
		if (execve(path, args, NULL) == -1)
		{
		error_msg(args[0], name);
		_exit(EXIT_FAILURE);
		}
		}
		else if (pid > 0)
			wait(NULL);
		else
			error_msg_f(args[0], name);
	}
		else
			error_msg_d(name);
	}
}
