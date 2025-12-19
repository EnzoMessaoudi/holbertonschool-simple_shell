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

typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node;

int simple_shell(void);
char *verify_path(char **str);
char *verify_env(char **str);
int _av(int argc, char *argv[]);
int read_line(void);
int _strtok(void);
void _printenv(void);
int env_v_prenv(int argc, char **argv, char **env);
char *_getenv(const char *name);
void print_path_dirs(void);
path_node *build_path_list(void);
void print_path_list(path_node *head);
void free_path_list(path_node *head);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int fork_wait_execve(void);
int super_simple_shell(void);
int file_exists(const char *path);
int _getpid(void);


# endif
