#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - finds a character in a string.
 * @s: The string being searched.
 * @c: The character being located.
 * Return: the location of c, else, NULL.
 */
char *_strchr(char *s, char c)
{
	int idx;

	for (idx = 0; s[idx]; idx++)
	{
		if (s[idx] == c)
			return (s + idx);
	}

	return (NULL);
}

/**
 * _strspn - calculates length of a prefix substring.
 * @s: The string.
 * @accept: The prefix to be measured.
 * Return: The number of bytes 
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int idx;

	while (*s)
	{
		for (idx = 0; accept[idx]; idx++)
		{
			if (*s == accept[idx])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - Compares two strings.
 * @s1: string1.
 * @s2: string 2.
 * Return: s1 vs s2 results
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to a string1.
 * @s2: Pointer to a string2.
 * @n: The first n bytes of the strings to be compared.
 * Return: -1 if s1 < s2, 0 if s1 = s2, else, 1 if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t input;

	for (input = 0; s1[input] && s2[input] && input < n; input++)
	{
		if (s1[input] > s2[input])
			return (s1[input] - s2[input]);
		else if (s1[input] < s2[input])
			return (s1[input] - s2[input]);
	}
	if (input == n)
		return (0);
	else
		return (-15);/*indicates that the comparison wasnt completed due to premature termination*/
}

