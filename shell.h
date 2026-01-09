# ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

extern char **environ;

int main(int argc, char **argv);

int simple_shell(char *shell_name);
void remove_quotes(char *str);
void print_prompt(void);
int command(char *comm, char **args);
int handle_success(int result, int *line);

int verify_path(int count, char **str);
char *resolve_path(char *cmd);
char *find_path(char *av);
pid_t fork_and_exec(char *path, char **argv);

int verify_env(int count, char **str);
void _printenv(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

# endif
