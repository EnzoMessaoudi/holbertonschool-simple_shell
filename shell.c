#include "shell.h"

/**
 * simple_shell - Shell-like function that can do simple tasks asked.
 *
 * Return: 0 on success
 */

int simple_shell(void)
{
	char *comm = NULL, *args[10], *token;
	size_t size = 0, len;
	int i = 0, c = 0;
	char *res;/** Ceci est un exemple de variable !!!!A changer!!!! */

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
		token = strtok(comm, " ");
		while (token != NULL)
		{
			args[c++] = token; /** Tableau qui prends un executable en première case et ses paramètre à la suite */
			token = strtok(NULL, " ");
		}
		res = verify_path(args); /** Fonction qui va vérifier si args est une commande dans le path et l'éxécuter si oui*/
		if (strcmp(res, "SUCCESS") == 0) /** Si la commande a été trouvé et éxécuter alors on recommence depuis la boucle */
		{
			i++;
			printf("Passe ici !");
			continue;
		}
		res = verify_env(args); /** Fonction qui vérifie les commandes en rapport avec l'environnement et éxécute si trouvé */
		if (strcmp(res, "SUCCESS") == 0) /** Si la commande a été trouvé et éxécuter alors on recommence depuis la boucle */
		{
			i++;
			printf("Passe ici !2");
			continue;
		}
			printf("shell: %d: %s : not found\n", i, comm); /** Si ça arrive à ici, alors cela veut dire que l'user à rentrer une mauvaise commande */
			i++;

	}
	free(comm);
	return (0);
}
