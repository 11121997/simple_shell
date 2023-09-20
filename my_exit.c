#include "shell.h"

#include "shell.h"

/**
  * inter_active - if in interactive mode or non interactive.
  */
void inter_active(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * ctrlc - if Ctrl C is pressed.
 *
 * @sn: signal number.
 */
void ctrlc(int sn)
{
	if (sn == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

/**
* E_O_F - handle End of File.
*
* @buf: buffer.
 */
void E_O_F(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	free(buf);

	exit(EXIT_SUCCESS);
}

/**
 * my_exit - function that exit shell.
 * @argv: commands arguments.
 */
void my_exit(char **argv)
{
	int x, y;

	if (argv[1])
	{
		y = a_to_i(argv[1]);
		if (y <= -1)
			y = 2;
		free_argv(argv);
		exit(y);
	}
	for (x = 0; argv[x]; x++)
		free(argv[x]);
	free(argv);
	exit(EXIT_SUCCESS);
}
