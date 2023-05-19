#include "S_shell.h"


/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: input helpers        */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

/**
 * get_args - Reads commands sent by the standard input.
 * @line: A buffer storage for the commands.
 * @exe_ret: Returned value of the previous executed command.
 * Return: NULL, if failed, else, a pointer to the stored command.
 */
char *get_args(char *line, int *exe_ret)
{
	size_t content_size = 0;
	ssize_t content;
	char *prompt = "$ ";

	if (line)
		free(line);

	content = _getline(&line, &content_size, STDIN_FILENO);
	if (content == -1)
		return (NULL);
	if (content == 1)
	{
		history++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		return (get_args(line, exe_ret));
	}

	line[content - 1] = '\0';
	variable_replacement(&line, exe_ret);
	handle_line(&line, content);

	return (line);
}

/**
 * call_args - handles and calls operators from commands
 * @args: Argument input.
 * @front: pointer pointing to the pointer pointing to the beginning of arguments
 * @exe_ret: Return value of the parent process' last executed command.
 * Return: The return value of the last executed command.
 */
int call_args(char **args, char **front, int *exe_ret)
{
	int return_value, idx;

	if (!args[0])
		return (*exe_ret);
	for (idx = 0; args[idx]; index++)
	{
		if (_strncmp(args[idx], "||", 2) == 0)
		{
			free(args[idx]);
			args[idx] = NULL;
			args = replace_aliases(args);
			return_value = run_args(args, front, exe_ret);
			if (*exe_ret != 0)
			{
				args = &args[++idx];
				idx = 0;
			}
			else
			{
				for (idx++; args[idx]; idx++)
					free(args[idx]);
				return (return_value);
			}
		}
		else if (_strncmp(args[idx], "&&", 2) == 0)
		{
			free(args[idx]);
			args[idx] = NULL;
			args = replace_aliases(args);
			ret = run_args(args, front, exe_ret);
			if (*exe_ret == 0)
			{
				args = &args[++idx];
				idx = 0;
			}
			else
			{
				for (idx++; args[idx]; idx++)
					free(args[idx]);
				return (return_value);
			}
		}
	}
	args = replace_aliases(args);
	return_value = run_args(args, front, exe_ret);
	return (return_value);
}

/**
 * run_args - Implements cmd execution.
 * @args: Argument input.
 * @front:  pointer pointing to the pointer pointing to the beginning of arguments
 * @exe_ret: The return value of the parent process' last executed command.
 * Return: The return value of the last executed command on the shell history.
 */
int run_args(char **args, char **front, int *exe_ret)
{
	int return_value, input;
	int (*builtin)(char **args, char **front);

	builtin = get_builtin(args[0]);

	if (builtin)
	{
		return_value = builtin(args + 1, front);
		if (return_value != EXIT)
			*exe_ret = return_value;
	}
	else
	{
		*exe_ret = execute(args, front);
		return_value = *exe_ret;
	}

	history++;

	for (input = 0; args[input]; input++)
		free(args[input]);

	return (return_value);
}

/**
 * handle_args - Executes the commands.
 * @exe_ret: The return value of the parent process' last executed command.
 * Return: END_OF_FILE (-2) if an end-of-file is read, else - -1 if !tokenized.
 * O/w - Exit value of the last executed command.
 */
int handle_args(int *exe_ret)
{
	int return_value = 0, idx;
	char **args, *line = NULL, **front;

	line = get_args(line, exe_ret);
	if (!line)
		return (END_OF_FILE);

	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (return_value);
	if (check_args(args) != 0)
	{
		*exe_ret = 2;
		free_args(args, args);
		return (*exe_ret);
	}
	front = args;

	for (idx = 0; args[idx]; idx++)
	{
		if (_strncmp(args[idx], ";", 1) == 0)
		{
			free(args[idx]);
			args[idx] = NULL;
			return_value = call_args(args, front, exe_ret);
			args = &args[++idx];
			idx = 0;
		}
	}
	if (args)
		return_value = call_args(args, front, exe_ret);

	free(front);
	return (return_value);
}

/**
 * check_args - Identifies any leading ';', ';;', '&&', or '||'.
 * @args: 2D pointer to tokenized commands and arguments.
 * Return: - 2 If a ';', '&&', or '||' is placed at an invalid position, else, - 0 as error status
 */
int check_args(char **args)
{
	size_t input;
	char *current, *next;

	for (input = 0; args[input]; input++)
	{
		current = args[input];
		if (current[0] == ';' || current[0] == '&' || current[0] == '|')
		{
			if (input == 0 || current[1] == ';')
				return (create_error(&args[input], 2));
			next = args[input + 1];
			if (next && (next[0] == ';' || next[0] == '&' || next[0] == '|'))
				return (create_error(&args[input + 1], 2));
		}
	}
	return (0);
}

