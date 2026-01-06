#include "shell.h"

/**
 * simple_shell - Shell-like function that can do simple tasks asked.
 *
 * Return: 0 on success
 */

int simple_shell(void)
{
	char *comm = NULL, *args[10], *token, *result;
	size_t size = 0, len;
	int i = 0, count = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
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
		token = strtok(comm, " ");
		count = 0;
		while (token != NULL)
		{
			args[count++] = token;
			token = strtok(NULL, " ");
		}
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
			printf("%s: %d: %s : not found\n", args[0], i, comm);
			i++;
	}
	free(comm);
	return (0);
}
