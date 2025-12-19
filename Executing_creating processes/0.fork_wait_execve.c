#include "shell.h"

/**
 * main - Forks 5 child processes to run /bin/ls -l /tmp
 *
 * Return: 0 on success
 */

int main(void)
{
	pid_t pid;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Fork");
			return (1);
		}

		else if (pid == 0)
		{
			execve("/bin/ls", args, NULL);
			perror("execve");
			_exit(1);
		}

		else
			wait(NULL);
	}

	printf("All children are terminated\n");
	return (0);
}
