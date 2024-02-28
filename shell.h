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
#define CHANGE_DIR 1
#define EXIT_SHELL 2
#define PERM_DENIED "Permission denied"
#define NOT_FOUND "not found"
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
char **parse_command(char *command, char *separator);
void Puts_(char *str);
void Errors(char *program, char *param, char *message, int Qexe);
int IntegerToString(int x, char str[]);
void RvsString(char *str, int len);
int Atoi(char *s);
void Print_Environment(char **env);
void Prompt_(void);
int Get_Path(char **param, char **env);
int BuiltExit(char *TheCommandand, int status);
int wait_(char **argv, char *command, int QExecutes);
int BuiltExit(char *command, int status);
int built_in(char *command, char **env, int status);
char *Get_Environment(char *var, char **env);
void Execute_(char *command, char **env);
#endif
