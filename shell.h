#ifndef SHELL_H
#define SHELL_H
/**
 * Header File - shell.h
 * Author: Amoni Kevin
 **/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
int main(int argc, char *argv[], char **env);
int Exec_(char **param, char **env);
void Into_Hshell(char **env, char **argv);
void removeSpaces(char *str);
char *String_copy(char *dest, char *src);
char *String_conc(char *dest, char *src);
char *String_dupl(char *str);
char *String_char(char *s, char c);
int String_comp(char *s1, char *s2);
int _String_Length(char *s);
int _strncmp(char *s1, char *s2, int n);
int Putchar_(char c);
#endif
