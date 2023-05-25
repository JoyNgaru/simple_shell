#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Errors file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

char *error_126(char **args);
char *error_127(char **args);

/**
 * error_126 - Creates an error message for permission denied failures.
 * @args: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_126(char **args)
{
	{
		char *error, *history_string;
		int length;

		history_string = _itoa(history);
		if (!history_string)
			return (NULL);

		length = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 24;
		error = malloc(sizeof(char) * (length + 1));
		if (!error)
		{
			free(history_string);
			return (NULL);
		}

		_strcpy(error, name);
		_strcat(error, ": ");
		_strcat(error, history_string);
		_strcat(error, ": ");
		_strcat(error, args[0]);
		_strcat(error, ": Permission denied\n");

		free(history_string);

	return (error);
	}
}

/**
 * error_127 - Outputs an error message for command not found failures.
 * @args: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_127(char **args)
{
	{
		char *err, *history_string;
		int length;

		history_string = _itoa(history);
		if (!history_string)
			return (NULL);

		length = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 16;
		err = malloc(sizeof(char) * (length + 1));
		if (!err)
		{
			free(history_string);
			return (NULL);
		}

		_strcpy(err, name);
		_strcat(err, ": ");
		_strcat(err, history_string);
		_strcat(err, ": ");
		_strcat(err, args[0]);
		_strcat(err, ": not found\n");

		free(history_string);
	return (err);
	}
}
