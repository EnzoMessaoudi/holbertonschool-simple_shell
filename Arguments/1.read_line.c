#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on successful execution
 */

int read_line(void)
{
	char *comm = NULL;
	size_t size = 0;

	printf("$ ");

	fflush(stdout);

	getline(&comm, &size, stdin);

	printf("%s", comm);

	free(comm);
	return (0);
}
