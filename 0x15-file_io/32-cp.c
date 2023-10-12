#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void error_and_exit(char *str, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", str);
	exit(exit_code);
}

int main(int argc, char **argv)
{
	int file_from, file_to;
	ssize_t read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_and_exit("Usage: cp file_from file_to", 97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
		error_and_exit("Error: Can't read from file NAME_OF_THE_FILE", 98);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to < 0)
	{
		close(file_from);
		error_and_exit("Error: Can't write to NAME_OF_THE_FILE", 99);
	}

	while ((read_bytes = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(file_to, buffer, read_bytes);
		if (write_bytes != read_bytes)
		{
			close(file_from);
			close(file_to);
			error_and_exit("Error: Can't write to NAME_OF_THE_FILE", 99);
		}
	}

	if (read_bytes < 0)
	{
		close(file_from);
		close(file_to);
		error_and_exit("Error: Can't read from file NAME_OF_THE_FILE", 98);
	}

	if (close(file_from) < 0)
		error_and_exit("Error: Can't close fd FD_VALUE", 100);

	if (close(file_to) < 0)
		error_and_exit("Error: Can't close fd FD_VALUE", 100);

	return (0);
}
