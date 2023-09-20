#include "shell.h"

#include "shell.h"

/**
 * main - main function loop for the shell
 * @ac: argument counter
 * @av: argument vector
 * @environ: array of enviromental variables.
 * Return: Always 0 success
 */
int main(int ac, char **av, char **environ)
{
	char *buf = NULL;
	char **cmd = NULL;
	size_t n = 0;
	ssize_t nchars_read = 0;
	int i = 0;
	(void)ac;

	while (1)
	{
		i++;
		inter_active();
		signal(SIGINT, ctrlc);
		nchars_read = getline(&buf, &n, stdin);
		if (nchars_read == EOF)
		{
			E_O_F(buf);
		}
		else if (*buf == '\n')
		{
			free(buf);
		}
		else
		{
			buf[_strlen(buf) - 1] = '\0';
			cmd = tokinzer(buf, " \0");
			free(buf);
			if (_strcmp(cmd[0], "exit") != 0)
				my_exit(cmd);
			else if (_strcmp(cmd[0], "cd") != 0)
				chd(cmd[1]);
			else
				child_process(cmd, av[0], environ, i);
			}
		fflush(stdin);
		n = 0, buf = NULL;
	}
	if (nchars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
