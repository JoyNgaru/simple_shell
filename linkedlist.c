#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *directory);
void free_list(list_t *head);

/**
 * add_alias_end - Adds a node to the tail of alias_t 
 * @head: A pointer pointing to the head of list_t.
 * @name: Name of the new node.
 * @value: Value of the new node
 * Return: NULL if an error occurs, else, a pointer to the new node in the list.
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last_node;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * add_node_end - Adds a node to the tail
 * @head: A pointer to the head.
 * @directory: The directory path for the new node to contain.
 * Return: a pointer to the new node, else, NULL on failure.
 */
list_t *add_node_end(list_t **head, char *directory)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last_node;

	if (!new_node)
		return (NULL);

	new_node->directory = directory;
	new_node->next = NULL;

	if (*head)
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * free_alias_list - Frees alias_t.
 * @head: Head of alias_t.
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_list - Frees a list_t linked list.
 * @head: The head of the list_t list.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->directory);
		free(head);
		head = next;
	}
}

