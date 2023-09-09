#include "main.h"

/**
 * _puts - prints a string, followed by a new line.
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	while (*str)
	{
	_putchar(*str);
	str++;
	}
}

/**
 * is_digit - checks if a string contains only digits
 * @str: pointer to the string to check
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
	if (*str < '0' || *str > '9')
		return (0);
	str++;
	}
	return (1);
}

/**
 * custom_atoi - convert a string to an integer.
 * @s: char type string
 * Return: integer converted
 */
int custom_atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (*s)
	{
	if (*s == '-')
	{
		sign *= -1;
	}
	else if (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
	}
	else
	{
		break;
	}
	s++;
	}

	return (sign * result);
}

/**
 * main - print the result of the multiplication, followed by a new line
 * @argc: number of arguments
 * @argv: array of argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
	_puts("Error");
	return (98);
	}

	int num1 = _atoi(argv[1]);
	int num2 = _atoi(argv[2]);
	int result = num1 * num2;

	print_int(result);
	_putchar('\n');

	return (0);
}
