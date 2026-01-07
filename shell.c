#include "shell.h"

/**
 * command - Splits a string into tokens
 *
 * @comm: Input string containing the command
 * @args: Array to store command and arguments
 *
 * Return: Number of arguments
 */

int command(char *comm, char **args)
{
	int count = 0;
	char *token = strtok(comm, " ");

	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;
	return (count);
}

/**
 * simple_shell - Shell-like function that can do simple tasks asked.
 * @shell_name: Name used to call the shell function
 * Return: 0 on success
 */

int simple_shell(char *shell_name)
{
	char *comm = NULL, *args[30], *result;
	size_t size = 0, len;
	int i = 1, count = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			fflush(stdout);
		}
		if (getline(&comm, &size, stdin) == -1)
			break;
		len = strcspn(comm, "\n");
		if (comm[len] == '\n')
			comm[len] = '\0';
		if (strcmp(comm, "exit") == 0)
			break;
		if (strcmp(comm, "") == 0)
		{
			i++;
			continue;
		}
		count = command(comm, args);
		result = verify_env(count, args);
		if (strcmp(result, "SUCCESS") == 0)
		{
			i++;
			continue;
		}
		result = verify_path(count, args);
		if (strcmp(result, "SUCCESS") == 0)
		{
			i++;
			continue;
		}
			printf("%s: %d: %s : not found\n", shell_name, i++, args[0]);
	}
	free(comm);
	return (0);
}
