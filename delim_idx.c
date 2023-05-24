#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: delimt file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - Finds the index showing the end of
 * the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter index.
 * Return: The delimiter index shwng end of intitial token pointed by str.
 */
int token_len(char *str, char *delim)
{
	int idx = 0, length = 0;

	while (*(str + idx) && *(str + idx) != *delim)
	{
		length++;
		idx++;
	}

	return (length);
}

/**
 * count_tokens - Counts the number of the delimited words.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 * Return: The number of words contained within str.
 */
int count_tokens(char *str, char *delim)
{
	int idx, tokens = 0, length = 0;

	for (idx = 0; *(str + idx); idx++)
		length++;

	for (idx = 0; idx < length; idx++)
	{
		if (*(str + idx) != *delim)
		{
			tokens++;
			idx += token_len(str + idx, delim);
		}
	}

	return (tokens);
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string.
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char **pointer, ptr;
	int idx = 0, tokens, content_tokens, letters, content_letters;

	tokens = count_tokens(line, delim);
	if (tokens == 0)
		return (NULL);

	pointer = malloc(sizeof(char *) * (tokens + 2));
	if (!pointer)
		return (NULL);

	for (content_tokens = 0; content_tokens < tokens; content_tokens++)
	{
		while (line[idx] == *delim)
			idx++;

		letters = token_len(line + idx, delim);

		ptr[content_tokens] = malloc(sizeof(char) * (letters + 1));
		if (!pointer[content_tokens])
		{
			for (idx -= 1; idx >= 0; idx--)
				free(pointer[idx]);
			free(pointer);
			return (NULL);
		}

		for (content_letters = 0; content_letters < letters; content_letters++)
		{
			ptr[content_tokens][content_letters] = line[idx];
			idx++;
		}

		ptr[content_tokens][content_letters] = '\0';
	}
	pointer[content_tokens] = NULL;
	pointer[content_tokens + 1] = NULL;

	return (pointer);
}

