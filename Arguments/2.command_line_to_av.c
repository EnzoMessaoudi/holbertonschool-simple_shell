#include "shell.h"

/**
 * main - Demonstrates how strtok splits a string into tokens
 *
 * Return: 0 on successful execution
 */

int _strtok(void)
{
	char str[] = "Coucou ! Comment ça va ?";
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return (0);
}
