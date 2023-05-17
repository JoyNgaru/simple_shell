#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Function to make a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_copyenv(void)
{
	char **new_environ;
	size_t length;
	int idx;

	for (length = 0; env[length]; length++)
		;

	new_environ = malloc(sizeof(char *) * (length + 1));
	if (!new_environ)
		return (NULL);

	for (idx = 0; env[idx]; idx++)
	{
		new_environ[idx] = malloc(_strlen(env[idx]) + 1);

		if (!new_environ[idx])
		{
			for (idx--; idx >= 0; idx--)
				free(new_environ[idx]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[idx], env[idx]);
	}
	new_environ[idx] = NULL;

	return (new_environ);
}

/**
 * free_env - Function to free environment copy.
 */
void free_env(void)
{
	int idx;

	for (idx = 0; env[idx]; idx++)
		free(env[idx]);
	free(env);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: Environmental variable name to get from PATH.
 * Return: If the ! environmental variable - NULL.
 *  else - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int idx, size;

	size = _strlen(var);
	for (idx = 0; env[idx]; idx++)
	{
		if (_strncmp(var, env[idx], size) == 0)
			return (&env[idx]);
	}

	return (NULL);
}
