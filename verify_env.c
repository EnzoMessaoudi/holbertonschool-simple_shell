#include "shell.h"

/**
* verify_env - Function that execute environnement function if founds
* @count: Number of arguements passed
* @str: Executable and its paramters passed by the user
* Return: Return 0 on success or -1 if failed
*/

int verify_env(int count, char **str)
{
	int i;

	if (strcmp(str[0], "setenv") == 0)
	{
		if (count < 4)
		{
			printf("Not enought arguments passed\n");
			return (0);
		}
		i = atoi(str[3]);
		_setenv(str[1], str[2], i);
		return (0);
	}
	else if (strcmp(str[0], "unsetenv") == 0)
	{
		_unsetenv(str[1]);
		return (0);
	}
	else if (strcmp(str[0], "env") == 0
	|| strcmp(str[0], "printenv") == 0)
	{
		_printenv();
		return (0);
	}

	return (-1);
}
