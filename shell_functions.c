#include "shell.h"

/**
* remove_quotes - Function that remove quotes from the command
* @str: Command we want to remove quotes from
*/
void remove_quotes(char *str)
{
	int i = 0, j = 0;
	char *tmp;

	tmp = malloc(strlen(str) + 1);
	if (tmp == NULL)
		return;

	for (; str[i]; i++)
	{
		if (str[i] != '"' && str[i] != '\'')
		{
			tmp[j] = str[i];
			j++;
		}
	}

	tmp[j] = '\0';
	strcpy(str, tmp);
	free(tmp);
}

/**
* print_prompt - Function that display the "$" prompt at each loop
*/
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
}

/**
* check_space_tab - Check if the user passed only tabs or spaces
* @comm: Commmand passed by the user
* Return: Return 1 if there are only tab or 0 if there is 1 character
*/

int check_space_tab(const char *comm)
{
	if (comm == NULL)
		return (1);
	while (*comm)
	{
		if (*comm != ' ' && *comm != '\t')
			return (0);
		comm++;
	}
	return (1);
}

/**
 * command - Splits a string into tokens
 *
 * @comm: Input string containing the command
 * @args: Array to store command and arguments
 *
 * Return: Number of arguments
 */

int command(char *comm, char **args)
{
	int count = 0;
	char *token = strtok(comm, " \t");

	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, " \t");
	}
	args[count] = NULL;
	return (count);
}

/**
* handle_success - Function that increment i if the command is found
* @result: Variable that check if the command was executed
* @line: On Success, i will be increment by one
* Return: Return 0 on success and 1 if not
*/

int handle_success(int result, int *line)
{
	if (result == 0 || result == 1)
	{
		(*line)++;
		return (0);
	}
	return (1);
}
