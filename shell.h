#ifndef SHELL_H
#define SHELL_H

/* libraries */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/* strings */
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int a_to_i(char *str);
char **tokinzer(char *str, const char *delim);

/* execute */
void execmd(char **av, char *name, char **environ, int ti);

/* my environment */
char **_getenv(char **environ);
void my_printenv(void);

/* exit my shell */
void my_exit(void);

/* handle end of file*/
void E_O_F(char *buf);

/*check if interactive mood or non*/
void inter_active(void);

/*check if CTRL+C is pressed*/
void ctrlc(int sn);

/* func create child process*/
void child_process(char **av, char *name, char **environ, int cy);

/* change directory func*/
int chd(const char *path);

/*memory managment*/
void free_argv(char **argv);
void exit_free(char **argv);

/*handle errors*/
void handle_errors(char *name, int ti, char **av);

#endif
