#include "shell.h"

/**
 * _printenv - Prints all environment variables
 *
 * Return: 0 on success
 */

void _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
