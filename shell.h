#ifndef SHELL_H
#define SHELL_H

/* libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* main.c */
int main(int ac, char **av);

/* strings */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
void _puts(char *str);
int _putchar(char c);

/* execute */
void execmd(char **av);

/* get the location */
char *get_location(char *cmd);

/* my environment */
char *_getenv(const char *name);
void my_printenv();

/* exit my shell */
void my_exit();

#endif
