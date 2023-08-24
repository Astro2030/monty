#include "monty.h"

/**
 * custom_getline - Read a line from a file stream
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the size of the allocated buffer.
 * @stream: File stream to read from.
 *
 * Return: If successful, the number of characters read.
 *         If an error occurs, -1 is returned.
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 1024;
	size_t pos = 0;
	char *buffer = (char *)malloc(bufsize);
	int c;

	if (!buffer)
	{
		return (-1);
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (pos >= bufsize - 1)
		{
			bufsize *= 2;
			buffer = (char *)realloc(buffer, bufsize);
			if (!buffer)
			{
				return (-1);
			}
		}
		buffer[pos++] = (char)c;
	}

	if (c == EOF && pos == 0)
	{
		free(buffer);
		return (-1);
	}

	buffer[pos] = '\0';
	*lineptr = buffer;
	*n = bufsize;
	return ((ssize_t)pos);
}
