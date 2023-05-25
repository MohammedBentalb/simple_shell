#include "shell.h"

/**
 * execute - exectute cmd
 * @j: data struct input
 * Return: void
 */

void execute(info *j)
{
	const char pre_wrd[] = MARK;

	signal(SIGINT, handle_ctrd);
	do {
	if (isatty(STDIN_FILENO))
		_write(pre_wrd);

	_read(j);
	if (_strlen(j->cmd) != 0)
	{
	chop(j, " ");
	if (!handler(j))
	{
		_locate(j);
		if (access(j->arg[0], F_OK) == -1)
		{
			perror(j->name);
		}
		else
		{
			run(j);
		}
	}
		arr_free(j->arg);
	}
	free(j->cmd);
	} while (1);
}
