#include "main.h"

#define BUFFER_SIZE 1024
#define USAGE "Usage: cp file_source file_dest\n"
#define ERR_NOREAD "Error: Can't read source file %s\n"
#define ERR_NOWRITE "Error: Can't write to destination file %s\n"
#define ERR_NOCLOSE "Error: Can't close file descriptor %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

void display_usage(void)
{
	dprintf(STDERR_FILENO, USAGE);
}

int open_source_file(const char *source_file)
{
	int source_fd = open(source_file, O_RDONLY);

	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, source_file);
		exit(98);
	}
	return (source_fd);
}

int open_destination_file(const char *destination_file)
{
	int dest_fd = open(destination_file, O_WRONLY |
			O_CREAT | O_TRUNC, PERMISSIONS);

	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOWRITE, destination_file);
		exit(99);
	}
	return (dest_fd);
}

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOCLOSE, fd);
		exit(100);
	}
}

void copy_file(int source_fd, int dest_fd)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, ERR_NOWRITE, dest_fd);
			close_file(source_fd);
			close_file(dest_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, source_fd);
		close_file(source_fd);
		close_file(dest_fd);
		exit(98);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		display_usage();
		exit(97);
	}

	int source_fd = open_source_file(argv[1]);
	int dest_fd = open_destination_file(argv[2]);

	copy_file(source_fd, dest_fd);

	close_file(source_fd);
	close_file(dest_fd);

	return (EXIT_SUCCESS);
}
