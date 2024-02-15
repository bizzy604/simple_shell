#include "shell.h"
/**
 * main - Entry into the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 * Return: Return 0
 **/
int main(int argc, char *argv[], char **env)
{	
	if (argc == 1)
	{
		Into_Hshell(env, argv);
	}
	else
	{
		/* executing the shell */
		if (Exec_(++argv, env))
			exit(127);
	}
	return (0);
}
