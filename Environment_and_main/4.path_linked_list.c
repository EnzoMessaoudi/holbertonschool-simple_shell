#include "shell.h"

/**
 * build_path_list - Builds a linked list of directories from PATH
 *
 * Return: Pointer to the head of the list, or NULL on failure
 */

path_node *build_path_list(void)
{
	char *path = _getenv("PATH");
	char *path_copy, *token;
	path_node *head = NULL, *tail = NULL, *new_node;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		new_node = malloc(sizeof(path_node));
		if (new_node == NULL)
			break;

		new_node->dir = strdup(token);
		if (new_node->dir == NULL)
		{
			free(new_node);
			break;
		}

		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

/**
 * print_path_list - Prints each directory in the PATH list
 * @head: Pointer to the head of the list
 */

void print_path_list(path_node *head)
{
	path_node *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}
}

/**
 * free_path_list - Frees the PATH linked list
 * @head: Pointer to the head of the list
 */

void free_path_list(path_node *head)
{
	path_node *current = head;
	path_node *tmp;

	while (current != NULL)
	{
		tmp = current->next;
		free(current->dir);
		free(current);
		current = tmp;
	}
}

/**
 * main - Entry point for testing the PATH list
 *
 * Return: 0 on success
 */

int main(void)
{
	path_node *path_list = build_path_list();

	if (path_list == NULL)
		printf("No PATH or failed to allocate memory\n");
	else
		print_path_list(path_list);

	free_path_list(path_list);
	return (0);
}
