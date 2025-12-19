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


int main(int argc, char *argv[]);
int main(void);
void main(void);
int main(int argc, char **argv, char **env);
char *_getenv(const char *name);
void print_path_dirs(void);
int file_exists(const char *path);
int main(int ac, char **av);
path_node *build_path_list(void);
void print_path_list(path_node *head);
void free_path_list(path_node *head);
int _setenv(const char *name, const char *value, int overwrite);

# endif
