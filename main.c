#include "shell.h"

/**
* main - Entry function
* @argc: arguments nunmber
* @argv: arguments
* @envp: environment
* Return: Return 0 (success)
*/


int main(int argc, char **argv, char **envp)
{
	char input[MAX_INPUT_SIZE];
	char *tokens[MAX_ARGS];
	char *paths_str = getenv("PATH");
	char *path = strtok(paths_str, ":");
	int i = 0;
	char *paths[MAX_PATHS];

	(void) argc;
	environ = envp;
	while (path != NULL && i < MAX_PATHS - 1)
	{
		paths[i++] = path;
		path = strtok(NULL, ":");
	}
	paths[i] = NULL;
	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		int num_chars = read(STDIN_FILENO, input, MAX_INPUT_SIZE - 1);

		if (num_chars == 0)
			exit(0);

	else if (num_chars == -1)
	{
		perror("read");
		continue;
	}
	input[num_chars] = '\0';
	int num_tokens = tokenize_input(input, tokens, MAX_ARGS);

	if (num_tokens == 0)
	{
		continue;
	}
	execute_command(tokens, argv[0], paths);
	}
return (0);
}
