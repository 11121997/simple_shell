#include "shell.h"

/**
 * *_strcpy - function that copies two strings
 * @dest: char type string
 * @src: char type string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *cp = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (cp);
}

/**
 * _strlen - function get the length of string
 * @s: pointer to string array
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * *_strcat - function that concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (r);
}

/**
 * _strcmp - function make comparison between two strings
 * @str1: first string
 * @str2: second string
 * Return: -1 if *str1 < *str2, 1 if *str1 > *str2, 0 otherwise
 */
int _strcmp(char *str1, char *str2)
{
	unsigned int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}

	return (1);
}
