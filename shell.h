#ifndef shell_H
#define shell_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern int errno;

/**
 * struct shoosecmd - array contains functions
 * @st: pointer
 * @f: Function pointer
 */

typedef struct shoosecmd
{
char *st;
int (*f)(char **arr);
} get_f;

int maker(char *arr[]);
void ctrc(int j);
int _atoi(char *s);
void type_p(int i);
int handle_exit(char *line[]);
int exe_cat(char *arr[]);
int _getstr(char *str);
int execute(char **ptr, char **args);
char **_strbr(char *line, char c);
int _getline(char **line, size_t *len);
int _strlen(char *str);
void _strcpy(char *src, char *dest);
int _strcmp(char *str, char *equ);
void _strcat(char *src, char *dest);
int exe_ls(char **arr);
int (*getcmd(char *str))(char **arr);
int exe_echo(char *line[]);
int exe_un(char **arr);
int exe_cd(char **arr);
int exe_pwd(char *arr[]);
int handle_env(char *line[]);
char _getchr(void);
char *hlp_cat(char *st, int n, char *str, char c);
#endif
