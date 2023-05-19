#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);

/**
 * free_args - Free space memory created by arguments.
 * @args: Null-terminated pointer pointing tor commands/arguments.
 * @front: pointer pointing to the pointer pointing to
 * the beginning of arguments
 */
void free_args(char **args, char **front)
{
	size_t content;

	for (content = 0; args[content] || args[content + 1]; content++)
		free(args[content]);

	free(front);
}

/**
 * get_pid - shows the current process ID.
 * Return: returns current PID else NULL on failure.
 */
char *get_pid(void)
{
	size_t content = 0;
	char *buffer_store;
	ssize_t data;

	data = open("/proc/self/stat", O_RDONLY);
	if (data == -1)
	{
		perror("Error! Not able to access file");
		return (NULL);
	}
	buffer_store = malloc(120);
	if (!buffer_store;)
	{
		close(data);
		return (NULL);
	}
	read(data, buffer_store, 120);

	while (buffer[content != ' ')
		content++;
	buffer[content] = '\0';
	close(data);
	return (buffer_store);
}

/**
 * get_env_value -shows matching values on env.
 * @beginning: environ to be compared.
 * @len: size of the envin to look for.
 * Return: If !variable, an empty string else value of the environ var
 */
char *get_env_value(char *beginning, int len)
{
	char **variable_address;
	char *sub = NULL, *temp, *variable;

	variable = malloc(len + 1);
	if (!variable)
		return (NULL);
	variable[0] = '\0';
	_strncat(variable, beginning, len);

	variable_address = _getenv(variable);
	free(variable);
	if (variable_address)
	{
		temp = *varable_address;
		while (*temp != '=')
			temp++;
		temp++;
		sub = malloc(_strlen(temp) + 1);
		if (sub)
			_strcpy(sub, temp);
	}

	return (sub);
}

/**
 * variable_replacement - substitution handler.
 * @line: pointer pointing to the pointer pointing to the
 * beginning of arguments
 * @exe_ret: A pointer to the last executed command.
 */
void variable_replacement(char **line, int *exe_ret)
{
	int old_content, new_content = 0, length;
	char *sub = NULL, *src_line = NULL, *dest_line;

	src_line = *line;
	for (old_content = 0; src_line[old_content]; old_content++)
	{
		if (src_line[old_content] == '$' && src_line[old_content + 1] &&
				src_line[old_content + 1] != ' ')
		{
			if (src_line[old_content + 1] == '$')
			{
				sub = get_pid();
				new_content = old_content + 2;
			}
			else if (src_line[old_content + 1] == '?')
			{
				sub = _itoa(*exe_ret);
				new_content = old_content + 2;
			}
			else if (src_line[old_content + 1])
			{
				/* extract the variable name to search for */
				for (new_content = old_content + 1; src_line[new_content] &&
						src_line[new_content] != '$' &&
						src_line[new_content] != ' '; new_content++)
					;
				length = new_content - (old_content + 1);
				sub = get_env_value(&src_line[old_content + 1], length);
			}
			dest_line = malloc(old_content + _strlen(sub)
					  + _strlen(&src_line[new_content]) + 1);
			if (!line)
				return;
			new_line[0] = '\0';
			_strncat(dest_line, src_line, old_content);
			if (sub)
			{
				_strcat(dest_line, sub);
				free(sub);
				sub = NULL;
			}
			_strcat(dest_line, &src_line[new_content]);
			free(src_line);
			*line = dest_line;
			src_line = dest_line;
			old_content = -1;
		}
	}
}
