#include "main.h"

#define BUFFER_SIZE 1024
#define USAGE "usage: cp file_source file_dest\n"
#define ERR_NOREAD "Error: Can't read source file %s\n"
#define ERR_NOWRITE "Error: Can't write dest %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PREMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - Copies the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: 1 on success, appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, USAGE), exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, argv[1]), exit(98);
	}

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PREMISSIONS);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOWRITE, argv[2]), exit(99);
	}

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, ERR_NOWRITE, argv[2]), exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, argv[1]), exit(98);
	}

	source_fd = close(source_fd);
	dest_fd = close(dest_fd);
	if (source_fd)
	{
		dprintf(STDERR_FILENO, ERR_NOCLOSE, source_fd), exit(100);
	}
	if (dest_fd)
	{
		dprintf(STDERR_FILENO, ERR_NOCLOSE, source_fd), exit(100);
	}

	return (EXIT_SUCCESS);
}
