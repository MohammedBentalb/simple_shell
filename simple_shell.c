#include "shell.h"

/**
 * set_info - Function that set info
 * @j: the struct collection of data
 * @name: grogram name
 */

void set_info(info *j, const char *name)
{
	j->name = name;
	j->cmd = NULL;
	j->status = EXIT_SUCCESS;
	j->arg = NULL;
	j->st = 0;
}

/**
 * main - init data
 * @argc: input size of @argv
 * @argv: input array of command line arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	info j;

(void)argc;
set_info(&j, argv[0]);
execute(&j);
return (0);
}
