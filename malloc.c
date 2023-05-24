#include "S_shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * malloc_checked- assign meory space
 * @b: amount of memory to be allocated
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *pointer;

	pointer = (void *)malloc(b);
	if (pointer == NULL)
		exit(98);
	return (pointer);

}
