#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strlen - Returns string length.
 * @s: A pointer to the characters string that are passed as arguments.
 * Return: str length.
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcpy - Copies string from src to dest
 * @dest: Pointer to the receiving file.
 * @src: Pointer to the file being copied.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t input;

	for (input = 0; src[input] != '\0'; input++)
		dest[input] = src[input];
	dest[input] = '\0';
	return (dest);
}

/**
 * _strcat - joins two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_file;
	const char *src_file;

	dest_file = dest;
	src_file =  src;

	while (*dest_file != '\0')
		dest_file++;

	while (*src_file != '\0')
		*dest_file++ = *src_file++;
	*dest_file = '\0';
	return (dest);
}

/**
 * _strncat - joins two strings by copying n bytes from source.
 * @dest: Pointer to dest string.
 * @src: Pointer to src string.
 * @n: n bytesto be copied.
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t input;

	for (input = 0; input < n && src[input] != '\0'; input++)
		dest[dest_len + input] = src[input];
	dest[dest_len + input] = '\0';

	return (dest);
}

