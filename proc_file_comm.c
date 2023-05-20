#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */
int cant_open(char *file_path);
int proc_file_commands(char *file_path, int *exe_ret);

/**
 * cant_open - If !file or lacks permissions to open -> error 127.
 * @file_path: Path to the file.
 * Return: error 127.
 */

int cant_open(char *file_path)
{
	char *error, *hist_str;
	int length;

	hist_str = _itoa(history);
	if (!hist_str)
		return (127);

	length = _strlen(name) + _strlen(hist_str) + _strlen(file_path) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(hist_str);
		return (127);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Can't open ");
	_strcat(error, file_path);
	_strcat(error, "\n");

	free(hist_str);
	write(STDERR_FILENO, error, length);
	free(error);
	return (127);
}

/**
 * proc_file_commands - Takes a file and attempts to run its commands
 * @file_path: Path to the file.
 * @exe_ret: Return value of the last executed command.
 * Return: If file couldn't be opened - 127,
 * If malloc fails - -1, else return value of the last command ran.
 */
int proc_file_commands(char *file_path, int *exe_ret)
{
	ssize_t file, b_read, input;
	unsigned int line_size = 0;
	unsigned int prev_size = 120;
	char *line, **args, **front;
	char buffer[120];
	int Return_value;

	history = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*exe_ret = cant_open(file_path);
		return (*exe_ret);
	}
	line = malloc(sizeof(char) * prev_size);
	if (!line)
		return (-1);
	do {
		b_read = read(file, buffer, 119);
		if (b_read == 0 && line_size == 0)
			return (*exe_ret);
		buffer[b_read] = '\0';
		line_size += b_read;
		line = _realloc(line, prev_size, line_size);
		_strcat(line, buffer);
		prev_size = line_size;
	} while (b_read);
	for (input = 0; line[input] == '\n'; input++)
		line[input] = ' ';
	for (; input < line_size; input++)
	{
		if (line[input] == '\n')
		{
			line[input] = ';';
			for (input += 1; input < line_size && line[input] == '\n'; input++)
				line[i] = ' ';
		}
	}
	variable_replacement(&line, exe_ret);
	handle_line(&line, line_size);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{
		*exe_ret = 2;
		free_args(args, args);
		return (*exe_ret);
	}
	front = args;

	for (input = 0; args[i]; input++)
	{
		if (_strncmp(args[input], ";", 1) == 0)
		{
			free(args[input]);
			args[input] = NULL;
			Return_value = call_args(args, front, exe_ret);
			args = &args[++input];
			input = 0;
		}
	}

	Return_value = call_args(args, front, exe_ret);

	free(front);
	return (Return_value);
}


