#include "shell.h"

char *verify_path(char **str)
{
	if (str == NULL || str[0] == NULL)
		return ("FALSE");

	if (strcmp(str[0], "ls") == 0)
		return ("SUCCESS");
	else
		return ("FALSE");

	return("G");
}