#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>



#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 16
#define MAX_PATHS 64
#define PROMPT "$ "
#define _S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define _stat(cmd, st) (stat(cmd, st))

extern char **environ;

/** main functions */
int tokenize_input(char *input, char **tokens, int max_tokens);
int find_executable(char *cmd, char *path, char **paths);
void execute_command(char **args, char *name, char **paths);

/**  Handlers */
void handle_clear(char **args);
void handle_env(char **args);
void handle_cd(char **args);
void handle_exit(char **args);
/**  Error printers */
void error_msg(char *arg, char *name);
void error_msg_f(char *arg, char *name);
void error_msg_d(char *name);


/**  Helping function */
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
void *_memset(void *s, int c, size_t n);
char *_strchr(char *s, int c);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, unsigned int n);
char *_strcat(char *dest, char *src);
int _atoi(char *s);


#endif
