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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * fork_and_exec - Forks a child process and executes a command
 * @path: Full path to executable
 * @argv: Argument array (NULL-terminated)
 *
 * Return: pid of child on success, -1 on fork failure
 */
pid_t fork_and_exec(char *path, char **argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		_exit(1);
	}

	return (pid);
}
/**
* verify_path - Check if the command is in the path and executable
* @count: Number of arguements passed
* @str: Command gived by the user
* Return: Return 0 on Success or -1 if fail
 */

int verify_path(int count, char **str)
{
	char *path, **argv;
	int i, status;
	pid_t pid, ret;

	if (strchr(str[0], '/'))
	{
		if (access(str[0], X_OK) != 0)
			return (-1);
		path = strdup(str[0]);
	}
	else
	{
		path = find_path(str[0]);
		if (path == NULL)
			return (-1);
	}
	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		free(path);
		return (-1);
	}
	argv[0] = path;
	for (i = 1; i < count; i++)
		argv[i] = str[i];
	argv[count] = NULL;
	pid = fork_and_exec(path, argv);
	if (pid == -1)
	{
		free(path);
		free(argv);
		return (-1);
	}
	ret = waitpid(pid, &status, 0);
	free(path);
	free(argv);
	if (ret == -1)
		return (-1);
	return (0);
}
