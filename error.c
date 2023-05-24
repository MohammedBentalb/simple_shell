#include "shell.h"

/**
* error_msg - Function that prints erorr message
* @arg: arg
* @name: name
*/

void error_msg(char *arg, char *name)
{
	char *error_msg = "No such file or directory\n";
	(void) arg;

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
}

/**
* error_msg_f - Function that prints erorr message
* @arg: arg
* @name: name
*/

void error_msg_f(char *arg, char *name)
{
	char *error_msg = "Fork error\n";
	(void) arg;

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, strlen(error_msg));

}

/**
* error_msg_d - Function that prints erorr message
* @name: name
*/

void error_msg_d(char *name)
{
	char *error_msg = "No such file or directory\n";

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
}
