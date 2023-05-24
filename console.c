#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * shellby_env - Outputs the current environment.
 * @args: Arguments input to the shell.
 * @front: A double pointer to the beginning of args.pointer
 * pointing to the pointer pointing to the beginning of arguments
 * Return: -1 If an error occurs else - 0.
 * Description: outputs one variable per ('variable' = 'value')
 */
int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int index;
	char nc = '\n';

	if (!env)
		return (-1);

	for (index = 0; env[index]; index++)
	{
		write(STDOUT_FILENO, env[index], _strlen(env[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}

/**
<<<<<<< HEAD
 * shellby_setenv - Changes or adds an environmental
 * variable to the PATH of the shell Command.
=======
 * shellby_setenv - Changes or adds an environmental variable to the
 * PATH of the shell Command.
>>>>>>> 735b797057805ac6ee03c210d56eb75555636f08
 * @args: Arguments input the shell.
 * @front: Pointer pointing to the pointer pointing to
 * the beginning of arguments
 * Description: args[1]:name of the new or existing PATH variable.
 *  args[2] value to set the new or changed variable to.
 * Return: If an error occurs - -1, otherwise - 0.
 */
int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t length;
	int idx;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		return (create_error(args, -1));
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (length = 0; env[length]; length++)
		;

	new_environ = malloc(sizeof(char *) * (length + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	for (idx = 0; env[idx]; idx++)
		new_environ[idx] = env[idx];

	free(env);
	env = new_environ;
	env[idx] = new_value;
	env[idx + 1] = NULL;

	return (0);
}

/**
 * shellby_unsetenv - Deletes an environmental variable from the PATH.
 * @args: Arguments input on the shell.
 * @front: Pointer pointing to the pointer pointing to
 * the beginning of arguments
 * Description: args[1] is the PATH variable to deleted.
  * Return: If an error occurs - -1, otherwise - 0.
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environ;
	size_t length;
	int idx, idx2;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	for (length = 0; env[length]; length++)
		;

	new_environ = malloc(sizeof(char *) * length);
	if (!new_environ)
		return (create_error(args, -1));

	for (idx = 0, idx2 = 0; env[idx]; idx++)
	{
		if (*env_var == env[idx])
		{
			free(*env_var);
			continue;
		}
		new_environ[idx2] = env[idx];
		idx2++;
	}
	free(env);
	env = new_environ;
	env[length - 1] = NULL;

	return (0);
}
