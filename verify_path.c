#include "shell.h"

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
	pid_t pid;

		path = resolve_path(str[0]);
		if (path == NULL)
			return (-1);
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
	if (waitpid(pid, &status, 0) == -1)
	{
		free(path);
		free(argv);
		return (-1);
	}
	free(path);
	free(argv);
	if (WIFEXITED(status) == 1)
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status) == 1)
		return (128 + WTERMSIG(status));
	return (-1);
}
