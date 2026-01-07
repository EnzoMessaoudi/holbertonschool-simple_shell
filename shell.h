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
int _av(int argc, char *argv[]);
int read_line(void);
int _strtok(void);
void _printenv(void);
int env_v_prenv(int argc, char **argv, char **env);
char *_getenv(const char *name);
void print_path_dirs(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int fork_wait_execve(void);
int super_simple_shell(void);
int file_exists(const char *path);
int _getpid(void);
char *find_path(char *av);


# endif
