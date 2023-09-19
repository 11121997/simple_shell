#include "shell.h"

/**
 * _puts - function that print string
 * @str: string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
}

/**
 * _putchar - function that print character
 * @c: character to print
 * Return: 1 on success, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
