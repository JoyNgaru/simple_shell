#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
/**
* read_textfile - function that we will use to read
* a text file and write its content on the POSIX standart output
* @filename: Name of text file.
* @letters: Number of letters it should read and print.
* The function `read_textfile` reads a text file and
* prints it to the POSIX standard output.
* It takes two arguments: `filename`, which is the name of the text file,
* and `letters`, which is the number of letters it should read and print¹.
* The function opens the file using the `open()` system call,
* reads the contents of the file into a buffer using
* the `read()` system call,
* writes the contents of the buffer to standard
* output using the `write()` system call,
* closes the file using the `close()` system call¹.
* Return: number of letters that were read, else 0
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_des, content_read, content_write;
	char *buff_str;
/*Let's check if the file is existent, if not, we return 0*/
	if (filename == NULL)
		return (0);
	/*if it is there, let's open to see its content*/
	file_des = open(filename, O_RDONLY);/*nosy :)*/

	if (file_des == -1) /*if there is nothing, we exit */
		return (0);
	/* aluta continua if there is content*/
	buff_str = malloc(sizeof(char) * letters);
	/*we allocate space for the content on our buffer storage */
	if (buff_str == NULL)
		return (0);/* if malloc failed we exit */

	content_read = read(file_des, buff_str, letters);
	if (content_read == -1)
	/*if the content being read is null then free the buffer and exit*/
	{
		free(buff_str);
		return (0);

	} /*content manipulation begins*/

	content_write = write(STDOUT_FILENO, buff_str, content_read);
	if (content_write == -1 || content_read != content_write)
	{
		free(buff_str);
		return (0);
	}
/*look if the content read==output & correct, if not clear buffer and exit*/
	free(buff_str);/*clear extra space*/
	close(file_des);/*close the file*/
	return (content_write); /*ouptut the content of the file*/
}
