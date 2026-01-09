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
	char *token = strtok(comm, " ");

	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, " ");
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
	if (result == 0)
	{
		(*line)++;
		return (0);
	}
	return (1);
}
