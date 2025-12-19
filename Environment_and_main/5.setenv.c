#include "shell.h"

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
	size_t i = 0, len;
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
	for (size_t j = 0; j < i; j++)
		new_env[j] = environ[j];
	new_env[i] = str;
	new_env[i + 1] = NULL;
	environ = new_env;
	return (0);
}


/* Test */
int main(void)
{
	_setenv("FOO", "hello", 1);
	_setenv("BAR", "world", 0);

	printf("FOO=%s\n", getenv("FOO"));
	printf("BAR=%s\n", getenv("BAR"));

	_setenv("FOO", "newvalue", 0);
	printf("FOO=%s\n", getenv("FOO"));

	_setenv("FOO", "newvalue", 1);
	printf("FOO=%s\n", getenv("FOO"));

	return (0);
}
