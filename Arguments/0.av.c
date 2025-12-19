#include "shell.h"

/*
 * main - Entry point of the program
 * @argc: Argument count (number of command-line arguments)
 * @argv: Argument vector (array of command-line argument strings)
 *
 * Return: 0 on successful execution
 */

int main(int argc, char *argv[])
{
	int i;


	for (i = 0; argv[i] != NULL; i++)
		printf("%d = %s\n", i, argv[i]);


	return (0);
}
