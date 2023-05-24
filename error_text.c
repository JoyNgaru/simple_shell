#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Errors file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
/**
 * error_env - Outputs an error message for shellby_env errors.
 * @args: Arguments passed to the command.
 * Return: The error string.
 */
char *error_env(char **args)
{
	char *err, *history_string;
	int size;

	history_string = _itoa(history);
	if (!history_string)
		return (NULL);

	args--;
	size = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 45;
	err = malloc(sizeof(char) * (size + 1));
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
	_strcat(err, ": Error! Failure to add/remove from environment\n");

	free(history_string);
	return (err);
}

/**
 * error_1 -Outputs an  error message for shellby_alias errors.
 * @args: Arguments passed to the command.
 * Return: The error string.
 */
char *error_1(char **args)
{
	char *err;
	int length;

	length = _strlen(name) + _strlen(args[0]) + 13;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
		return (NULL);

	_strcpy(err, "alias: ");
	_strcat(err, args[0]);
	_strcat(err, " Sorry! not found\n");

	return (err);
}

/**
 * error_2_exit - Outputs an error message for shellby_exit errors.
 * @args: Arguments passed to the command.
 * Return: The error string.
 */
char *error_2_exit(char **args)
{
	char *err, *history_string;
	int length;

	history_string = _itoa(history);
	if (!history_string)
		return (NULL);

	length = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 27;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_string);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, history_string);
	_strcat(err, ": exit: Illegal number: ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(history_string);
	return (err);
}

/**
 * error_2_cd - Outputs an error message for shellby_cd errors.
 * @args: Arguments passed to the command.
 * Return: The error string.
 */
char *error_2_cd(char **args)
{
	char *err, *history_string;
	int length;

	history_string = NULL;

	if (!history_string)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	length = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_string);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, history_string);
	if (args[0][0] == '-')
		_strcat(err, ": cd: Illegal option ");
	else
		_strcat(err, ": cd: can't cd to ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(history_string);
	return (err);
}

/**
 * error_2_syntax - Outputs an error message for syntax errors.
 * @args: Arguments passed to the command.
 * Return: The error string.
 */
char *error_2_syntax(char **args)
{
	char *err, *history_string;
	int length;

	history_string = _itoa(history);
	if (!history_string)
		return (NULL);

	length = _strlen(name) + _strlen(history_string) + _strlen(args[0]) + 33;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_string);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, history_string);
	_strcat(err, ": Syntax error: \"");
	_strcat(err, args[0]);
	_strcat(err, "\" unexpected\n");

	free(history_string);
	return (err);
}
