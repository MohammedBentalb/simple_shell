#include "shell.h"
/**
* main - Entry function
* @argc: argumment numeber
* @argv: arguments
* Return: Return (0);
*/

int main(int argc, char **argv)
{
	char *row;

	(void) argc;
	row = malloc(256);
	if (!row)
	{
	perror("Allocation");
	exit(1);
	}

	if (!isatty(STDIN_FILENO))
	{
	if (_getstr(row) == (-1))
	{
		write(1, "\n", 2);
		exit(1);
	}
	if (execute(_strbr(row, ' '), argv) == -1)
	{
		perror("Error");
	}

	exit(0);
	}

	while (1)
	{
	type_p(0);
	if (_getstr(row) == (-1))
	{
		write(1, "\n", 2);
		exit(0);
	}

	if ((execute(_strbr(row, ' '), argv)) == -1)
		perror("Error");
	};

return (0);
}
