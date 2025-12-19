#include "shell.h"

/**
 * file_exists - Checks if a file exists at the given path
 * @path: Path to the file
 *
 * Return: 1 if file exists, 0 otherwise
 *
 */

int file_exists(const char *path)
{
	struct stat st;

	return (stat(path, &st) == 0);
}

/**
 * main - Searches for given filenames in directories listed in PATH
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, 1 if usage error or PATH not set
 *
 */

int main(int ac, char **av)
{
	char *path_env;
	char *path_copy;
	char *dir;
	char full_path[1024];
	int i = 1;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", av[0]);
		return (1);
	}

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (1);

	while (i < ac)
	{
		path_copy = strdup(path_env);
		if (path_copy == NULL)
			return (1);

		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			sprintf(full_path, "%s/%s", dir, av[i]);

			if (file_exists(full_path))
			{
				printf("%s\n", full_path);
				break;
			}
			dir = strtok(NULL, ":");
		}
		if (dir == NULL)
			printf("%s: not found\n", av[i]);
		free(path_copy);
		i++;
	}
	return (0);
}
