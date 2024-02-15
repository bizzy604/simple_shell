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
#endif
