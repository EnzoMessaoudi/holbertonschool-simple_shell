#include "shell.h"

/**
 * main - Prints all environment variables
 *
 * Return: 0 on success
 */

void main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
