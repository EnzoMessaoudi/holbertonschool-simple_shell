#include "shell.h"

/**
* verify_env - Function that execute environnement function if founds
* @str: Executable and its paramters passed by the user
* Return: Return SUCCESS if the function find a executable or FALSE if not
*/

char *verify_env(char **str)
{
	int i, j = 0;

	if (str == NULL || str[0] == NULL)
		return ("FALSE");

	while (str[j] != NULL)
	j++;

	if (strcmp(str[0], "setenv") == 0)
	{
		if (j < 4)
		{
			printf("Not enought arguments passed\n");
			return ("SUCCESS");
		}
		i = atoi(str[3]);
		_setenv(str[1], str[2], i);
		return ("SUCCESS");
	}
	else if (strcmp(str[0], "unsetenv") == 0)
	{
		_unsetenv(str[1]);
		return ("SUCCESS");
	}
	else if (strcmp(str[0], "env") == 0
	|| strcmp(str[0], "printenv") == 0)
	{
		_printenv();
		return ("SUCCESS");
	}

	return ("FALSE");
}
