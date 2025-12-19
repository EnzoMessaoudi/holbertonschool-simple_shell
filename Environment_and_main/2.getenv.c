#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable to search for
 *
 * Return: Pointer to the value of the environment variable,
 *         or NULL if the variable is not found
 */

char *_getenv(const char *name)
{
	int len = strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
		env++;
	}
	return (NULL);
}

