#include "shell.h"

/**
 * main - Compares the env parameter with the global environ variable
 * @argc: Argument count (unused)
 * @argv: Argument vector (unused)
 * @env:  Environment variables passed to main
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	printf("Address of env parameter: %p\n", (void *)env);
	printf("Address of environ variable: %p\n", (void *)environ);

	return (0);
}
