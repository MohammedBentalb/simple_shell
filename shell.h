#ifndef SHELL_H
#define SHELL_H



#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define MARK "#csisfun$ "

extern char **environ;

/**
 * struct info -Function that keeps imp data
 * @arg: arguments
 * @cmd: cmd input
 * @name: name of program
 * @status: exit state
 * @st: 1 || 0
 */
typedef struct info
{
	char **arg;
	char *cmd;
	const char *name;
	int status;
	int st;
} info;

/**
 * struct handle - collection of data
 * @c: char
 * @f: function pointer
 */
typedef struct handle
{
	const char *c;
	void (*f)(info *j);
} handle;

/* handling functions */
int handler(info *j);
void handle_exit(info *j);
void handle_env(info *j);
void handle_stenv(info *j);
void handle_unstenv(info *j);
void handle_cd(info *j);

char *_getenv(char *str);
int _locate(info *j);
int _setenv(info *j, char *var, char *value);
void run(info *j);
void handle_ctrd(int sig);
void execute(info *j);
void _write(const char *s);
void arr_free(char **arr);
void chop(info *j, const char *str);
void set_info(info *j, const char *name);
void _read(info *j);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **nw_env(char *ptr, char *value);
char *set_ent(char *ptr, char *value);
void _perror(const char *name, const char *err);
char *_strdup(const char *ptr);
int _isnumber(const char *s);
int _isdigit(int s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
void _cut(char *c);
void *_realloc(void *p, unsigned int size);
unsigned int _strlen(char *s);
int _strcmp(const char *fst, const char *sec);
int _strncmp(const char *fst, const char *sec, int num);
int _getln_side(char **lane, size_t *n);

#endif
