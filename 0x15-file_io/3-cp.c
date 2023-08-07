
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for a buffer
 * @file: name of file buffer is storing chars
 *
 * Return: pointer to newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close file descriptors
 * @fd: file descriptor to be closed
 */
void close_file(int fd)
{
	int p;

	p = close(fd);

	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copy content of file to another
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to arguments
 *
 * Return: 0 on success
 *
 * Description: when argument count is incorrect - exit code 97.
 * when file_from does not exist or cannot read - exit code 98.
 * when file_to cannot be created or written to - exit code 99.
 * when file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, q, a;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	q = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		a = write(to, buffer, q);
		if (to == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		q = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (q > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
