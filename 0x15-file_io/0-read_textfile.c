#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and
 * prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 * Return: The actual number of letters read and printed. 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t read_count, write_count;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	read_count = read(fd, buf, letters);
	if (read_count == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	buf[read_count] = '\0';

	write_count = write(STDOUT_FILENO, buf, read_count);
	if (write_count == -1 || write_count != read_count)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (read_count);
}
