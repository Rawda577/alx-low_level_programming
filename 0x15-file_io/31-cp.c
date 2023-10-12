#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @ac: The argument count.
 * @av: The argument vector.
 * Return: 0 on success, appropriate error code on failure.
 */
int main(int ac, char *av[])

	int source_fd, destination_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
	{
		dprintf(2, "Usage: %s source_file destination_file\n", av[0]);
		exit(97);
	}

	source_fd = open(av[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	destination_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (destination_fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		close(source_fd);
		exit(99);
	}

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(destination_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]);
			close(source_fd);
			close(destination_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		close(source_fd);
		close(destination_fd);
		exit(98);
	}

	if (close(source_fd) == -1 || close(destination_fd) == -1)
	{
		dprintf(2, "Error: Can't close file descriptor\n");
		exit(100);
	}
	return (0);
}
