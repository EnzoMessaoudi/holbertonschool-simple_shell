#include "../shell.h"

/**
 * main - A very simple shell that supports 'ls' and 'exit' commands
 *
 * Return: 0 on success
 */

int _simple_shell(void)
{
	char *comm = NULL;
	size_t size = 0, len;
	pid_t pid;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

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
		if (strcmp(comm, "ls") == 0)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				break;
			}
			if (pid == 0)
			{
				execve("/bin/ls", args, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			wait(NULL);
		}
		else
			printf("shell: 1: %s : not found\n", comm);
	}
	free(comm);
	return (0);
}