#include "shell.h"

/**
* main - Main function
* @argc: Number of arguments passed
* @argv: How the user call the shell function
* Return: Return 1
 */

int main(int argc, char **argv)
{
	(void)argc;
	simple_shell(argv[0]);

	return (0);
}
