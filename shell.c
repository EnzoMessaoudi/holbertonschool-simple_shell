#include "shell.h"

/**
 * _simple_shell - A very simple shell that supports 'ls' and 'exit' commands
 *
 * Return: 0 on success
 */

int _simple_shell(void)
{
	char *comm = NULL;
	size_t size = 0, len;
	int i = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&comm, &size, stdin) == -1)
			break;
		len = strcspn(comm, "\n");

		if (comm[len] == '\n')
			comm[len] = '\0';
		if (strcmp(comm, "exit") == 0)
			break;
		if (strcmp(comm, "") == 0)
		{
			i++;
			continue;
		}
		/**1- Strtok sur comm(saisie de ce que l'utilisateur a mis)*/
		/**2- Appeler une fonction (strtok de comm et combien d'arguments) qui check si la commande saise est une fonction du path puis vérifier si les données retournées sont positives */
		/**3- Appeler une fonction (strtok de comm et combien d'arguments) qui check si la commande saisie touche à l'environnement */
			printf("shell: %d: %s : not found\n", i, comm);
			i++;

	}
	free(comm);
	return (0);
}