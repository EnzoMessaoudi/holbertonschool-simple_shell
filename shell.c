#include "shell.h"

/**
 * simple_shell - Shell-like function that can do simple tasks asked.
 * @shell_name: Name used to call the shell function
 * Return: 0 on success
 */

int simple_shell(char *shell_name)
{
	char *comm = NULL, *args[30];
	size_t size = 0, len;
	int i = 1, count = 0, result = 0, last_result = 0;

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
		if (strcmp(comm, "") == 0)
		{
			i++;
			continue;
		}
		count = command(comm, args);
		if (strcmp(args[0], "exit") == 0)
		{
			free(comm);
			exit(last_result);
		}
		result = verify_env(count, args);
		last_result = result;
		if (handle_success(result, &i) == 0)
			continue;
		result = verify_path(count, args);
		last_result = result;
		if (handle_success(result, &i) == 0)
			continue;
		printf("%s: %d: %s : not found\n", shell_name, i++, args[0]);
	}
	free(comm);
	return (0);
}
