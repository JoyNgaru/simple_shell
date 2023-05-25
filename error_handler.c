#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: handler file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - Give a counts of the digit length of a number.
 * @num: Measured length.
 * Return: length.
 */
int num_len(int num)
{
	unsigned int count;
	int length = 1;

	if (num < 0)
	{
		length++;
		count = num * -1;
	}
	else
	{
		count = num;
	}
	while (count > 9)
	{
		length++;
		count /= 10;
	}

	return (length);
}

/**
 * _itoa - Converter from an integer to a string
 * @num: Number to be converted.
 * Return: The result
 */
char *_itoa(int num)
{
	char *buffer_store;
	int length = num_len(num);
	unsigned int number;

	buffer_store = malloc(sizeof(char) * (length + 1));
	if (!buffer_store)
		return (NULL);

	buffer_store[length] = '\0';

	if (num < 0)
	{
		number = num * -1;
		buffer_store[0] = '-';
	}
	else
	{
		number = num;
	}

	length--;
	do {
		buffer_store[length] = (number % 10) + '0';
		number /= 10;
		length--;
	} while (number > 0);

	return (buffer_store);
}


/**
 * create_error - Outputs an error msg to stderr.
 * @args: Arguments being input.
 * @err: The error
 * Return: The error message.
 */
int create_error(char **args, int err)
{
	char *error_content;

	switch (err)
	{
	case -1:
		error_content = error_env(args);
		break;
	case 1:
		error_content = error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error_content = error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error_content = error_2_syntax(args);
		else
			error_content = error_2_cd(args);
		break;
	case 126:
		error_content = error_126(args);
		break;
	case 127:
		error_content = error_127(args);
		break;
	}
	write(STDERR_FILENO, error_content, _strlen(error_content));

	if (error_content)
		free(error_content);
	return (err);

}
