#include "shell.h"
#include <limits.h>

/**
 * find_path - Searches for given filenames in directories listed in PATH
 * @ac: Argument count
 * @av: Argument value
 * Return: SUCCES on success, FALSE if usage error or PATH not set
 */

char *find_path(int ac, char **av)
{
	char *path_env, *path_copy, *dir, *full_path;
	int i = 0;

	if (ac == 0 || av == 0)
		return (NULL);

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	while (i < ac)
	{
		path_copy = strdup(path_env);
		if (path_copy == NULL)
			return (NULL);

		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			full_path = malloc(PATH_MAX);
			if (full_path == NULL)
			{
				free(path_copy);
				return (NULL);
			}
			sprintf(full_path, "%s/%s", dir, av[i]);

			if (access(path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
		i++;
	}
	return (NULL);
}

/**
* verify_path - Check if the command is in the path and executable
* @count: Number of arguements passed
* @str: Command gived by the user
* Return: Return SUCCESS if the command is good or FALSE if not
 */

char *verify_path(int count, char **str)
{
	int i;
	char *path;
	char **argv;
	pid_t pid;

	path = find_path(count, str);
	if (path == NULL)
		return ("FALSE");

	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
	{
		free(path);
		return ("FALSE");
	}
	argv[0] = str[0];
	for (i = 1; i < count; i++)
		argv[i] = str[i];

	argv[count] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("FORK");
		return ("FALSE");
	}
	else if (pid == 0)
	{
		execve(path, argv, NULL);
		perror("execve");
		_exit(1);
	}
	free(path);

	return ("SUCCESS");
}
