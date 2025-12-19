#include "shell.h"

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
