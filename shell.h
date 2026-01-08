# ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int simple_shell(char *shell_name);
int verify_path(int count, char **str);
int verify_env(int count, char **str);
void _printenv(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _getpid(void);
char *find_path(char *av);
pid_t fork_and_exec(char *path, char **argv);


# endif
