#include "shell.h"
#include <limits.h>

/**
 * find_path - Searches for given filenames in directories listed in PATH
 * @comm: Command passed by the user
 * Return: SUCCES on success, FALSE if usage error or PATH not set
 */

char *find_path(char *comm)
{
	char *path_env, *path_copy, *dir, full_path[PATH_MAX];
	char *result;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, comm);

		if (access(full_path, X_OK) == 0)
		{
			result = strdup(full_path);
			free(path_copy);
			return (result);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
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

	path = find_path(str[0]);
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
		free(path);
		free(argv);
		return ("FALSE");
	}
	else if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		_exit(1);
	}
	else
		wait(NULL);
	free(path);
	free(argv);
	return ("SUCCESS");
}
