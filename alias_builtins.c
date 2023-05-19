#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/**
 * shellby_alias - command to output aliases
 * @args: input arguments passed to the shell.
 * @front: Pointer pointing to the pointer pointing to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int content, rtnt = 0;
	char *value;

	if (!args[0])
	{
		while (temp)
		{
			print_alias(temp);
			temp = temp->next;
		}
		return (rtn);
	}
	for (content = 0; args[content]; content++)
	{
		temp = aliases;
		value = _strchr(args[content], '=');
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(args[content], temp->name) == 0)
				{
					print_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				rtn = create_error(args + content, 1);
		}
		else
			set_alias(args[content], value);
	}
	return (rtn);
}

/**
 * set_alias - function to create or rename an alias with a name and a value
 * @var_name: Alias name
 * @value: alias value starting with '='.
 */
void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int size, contents_name, contents_value;
	char *new_value;

	*value = '\0';
	value++;
	size = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (size + 1));
	if (!new_value)
		return;
	for (contents_name = 0, contents_value = 0; value[contents_name];
			contents_name++)
	{
		if (value[contents_name] != '\'' && value[contents_name] != '"')
			new_value[contents_value++] = value[contents_name];
	}
	new_value[contents_value] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		add_alias_end(&aliases, var_name, new_value);
}

/**
 * print_alias - Function to output the alias (name='value').
 * @alias: Pointer pointing to an alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_string;
	int size = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (size + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, size);
	free(alias_string);
}
/**
 * replace_aliases - checks for same aliases and changes their names and value
 * @args: pointer to the arguments.
 * Return: pointer to the arguments.
 */
char **replace_aliases(char **args)
{
	alias_t *temp;
	Int content;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (content = 0; args[content]; content++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[content], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(args[content]);
				args[content] = new_value;
				content--;
				break;
			}
			temp = temp->next;
		}
	}

	return (args);
}
