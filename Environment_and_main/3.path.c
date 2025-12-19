#include "shell.h"

/**
 * print_path_dirs - Prints each directory listed in the PATH variable
 *
 * Description:
 *   Retrieves the PATH environment variable, duplicates it,
 *   then splits it using ':' as a delimiter and prints each directory.
 */

void print_path_dirs(void)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *dir;

	if (path == NULL)
	{
		printf("PATH not found\n");
		return;
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
}

/**
 * main - Entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	print_path_dirs();
	return (0);
}
