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

/**
 * _setenv - Adds or modifies an environment variable
 * @name: Name of the variable
 * @value: Value to set
 * @overwrite: If non-zero, overwrite existing variable
 *
 * Return: 0 on success, -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t i = 0, len, j;
	char *str, **new_env;

	if (name == NULL || value == NULL)
		return (-1);
	len = strlen(name) + strlen(value) + 2;
	str = malloc(len);
	if (str == NULL)
		return (-1);
	sprintf(str, "%s=%s", name, value);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
			environ[i][strlen(name)] == '=')
		{
			if (overwrite == 0)
			{
				free(str);
				return (0);
			}
			free(environ[i]);
			environ[i] = str;
			return (0);
		}
		i++;
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (new_env == NULL)
	{
		free(str);
		return (-1);
	}
	for (j = 0; j < i; j++)
		new_env[j] = environ[j];
	new_env[i] = str;
	new_env[i + 1] = NULL;
	if (environ != NULL)
		free(environ);
	environ = new_env;
	return (0);
}

/**
* _unsetenv - Function that remove a environnement variable
* @name: Name of the variable we want to remove
* Return: 0 on success or -1 on failure
*/

int _unsetenv(const char *name)
{
	size_t i = 0, j;
	size_t len;

	if (name == NULL)
		return (-1);

	len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j] != NULL; j++)
				environ[j] = environ[j + 1];

			return (0);
		}
		i++;
	}
	return (0);
}

/**
* verify_env - Function that execute environnement function if founds
* @count: Number of arguements passed
* @str: Executable and its paramters passed by the user
* Return: Return SUCCESS if the function find a executable or FALSE if not
*/

char *verify_env(int count, char **str)
{
	int i;

	if (strcmp(str[0], "setenv") == 0)
	{
		if (count < 4)
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
