#include "shell.h"

/**
 * main - main function loop for the shell
 * @ac: argument counter
 * @av: argument vector
 * Return: Always 0 success
 */
int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;
	int i;

	(void)ac;
	while (1)
	{
		_puts(prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			_putchar('\n');
			return (-1);
		}
		lineptr_cp = malloc(sizeof(char) * nchars_read);
		if (lineptr_cp == NULL)
		{
			perror("tsh: memory alloction error");
			return (-1);
		}
		_strcpy(lineptr_cp, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		av = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_cp, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(av[i], token);
			if (_strcmp(token, "exit") == 0)
			{
				my_exit();
			}
			if (_strcmp(token, "env") == 0)
			{
				my_printenv();
			}
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		execmd(av);
	}
	free(av);
	free(lineptr);
	free(lineptr_cp);

	return (0);
}
