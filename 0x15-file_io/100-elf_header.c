#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_header - Print information from the ELF header
 * @ehdr: Pointer to the ELF header
 */
void print_elf_header(Elf64_Ehdr *ehdr) {
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
	printf("  Class:				%s\n", (ehdr->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:					%s\n", (ehdr->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:				%d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("  OS/ABI:				%s\n", (ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Other");
	printf("  ABI Version:				%d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("  Type:					%d\n", ehdr->e_type);
	printf("  Entry point address:			%#lx\n", ehdr->e_entry);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[]) {
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2) {
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
	fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
	return 98;
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
	fprintf(stderr, "Error: Cannot read ELF header\n");
	close(fd);
	return 98;
	}

	if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
	fprintf(stderr, "Error: Not an ELF file\n");
	close(fd);
	return 98;
	}

	print_elf_header(&ehdr);

	close(fd);
	return 0;
}
