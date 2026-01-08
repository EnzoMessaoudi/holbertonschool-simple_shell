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
* handle_success - Function that increment i if the command is found
* @result: Variable that check if the command was executed
* @line: On Success, i will be increment by one
* Return: Return 0 on success and 1 if not
*/

int handle_success(int result, int *line)
{
	if (result == 0)
	{
		(*line)++;
		return (0);
	}
	return (1);
}

/**
 * simple_shell - Shell-like function that can do simple tasks asked.
 * @shell_name: Name used to call the shell function
 * Return: 0 on success
 */

int simple_shell(char *shell_name)
{
	char *comm = NULL, *args[30];
	size_t size = 0, len;
	int i = 1, count = 0, result = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		if (getline(&comm, &size, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		len = strcspn(comm, "\n");
		if (comm[len] == '\n')
			comm[len] = '\0';
		if (strcmp(comm, "exit") == 0)
			exit(result);
		if (strcmp(comm, "") == 0)
		{
			i++;
			continue;
		}
		count = command(comm, args);
		result = verify_env(count, args);
		if (handle_success(result, &i) == 0)
			continue;
		result = verify_path(count, args);
		if (handle_success(result, &i) == 0)
			continue;
		printf("%s: %d: %s : not found\n", shell_name, i++, args[0]);
	}
	free(comm);
	return (0);
}
