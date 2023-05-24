#include "shell.h"

/**
* tokenize_input - Function that tokenizes a given input
* @input: input
* @tokens: tokens
* @max_tokens: max
* Return: Return i
*/

int tokenize_input(char *input, char **tokens, int max_tokens)
{
	int i = 0;
	char *token = strtok(input, " \n");

	while (token != NULL && i < max_tokens - 1)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
return (i);
}
