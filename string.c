#include "shell.h"

/**
 * *_strcpy - function that copies two strings
 * @dest: char type string
 * @src: char type string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _strlen - function get the length of string
 * @s: pointer to string array
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * *_strdup - function that duplicate string
 * @str: string to duplicate
 * Return: pointer to duplicate string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--str;
	return (r);
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
	while (*src)
		*dest++ = *src++;
	*dest = *src;
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
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
