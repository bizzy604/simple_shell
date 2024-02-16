#include "shell.h"
int wait_(char **argv, char *Command, int QExecutes);
/**
 * Into_Hshell - Program to start the shell, process & loop of instructions
 * @env:  enviroment variables array
 * @argv: argument vector array
 **/
void Into_Hshell(char **env, char **argv)
{
	size_t sizebuffer;
	char *Command = NULL;
	pid_t pid;
	int InBuilt = 0;
	static int Statuss;
	static int qExecutes = 1;
	ssize_t qCharComm;

	Command = NULL;
	Prompt_();
	while ((qCharComm = getline(&Command, &sizebuffer, stdin)) != EOF)
	{
		if (String_comp(Command, "\n") != 0)
		{
			InBuilt = built_in(Command, env, Statuss);
			if (InBuilt == CHANGE_DIR)
			{	free(Command);
				Command = NULL;
				continue;
			};
			if (InBuilt == EXIT_SHELL)
			{	free(Command);
				exit(0);
			}
			pid = fork();
			if (pid > 0)
			{
				Statuss = wait_(argv, Command, qExecutes);
				qExecutes++;
			}
			else if (pid == 0)
				{
				Execute_(Command, env);
				}
			if (pid == -1)
				perror("Error fork");
		}
		else
		{	free(Command);
			Command = NULL;
		}
		Prompt_();
	}
	free(Command);
	if (Statuss != 0)
		exit(Statuss);
}
/**
 * Execute_ - function to Execute_ a Command whith the enviroment
 * @Command: variable to take-in a Command
 * @env: var to store enviroment
 * Return: void
 **/
void Execute_(char *Command, char **env)
{
	char **parameter;
	int IndEx = 0;
	char *forCommand;

	forCommand = strdup(Command);
	removeSpaces(forCommand);
	if (_String_Length(forCommand) == 1)
	{
		free(forCommand);
		_exit(0);
	}
	free(forCommand);

	parameter = parse_command(Command, " ");
	if (parameter != NULL)
	{
		if (String_comp(parameter[0], "env") == 0)
		{
			Print_Environment(env);
			/*free(parameter); VALGRIND*/
		} else
		{
			IndEx = Exec_(parameter, env);
			if (IndEx == 1)
			{
				free(Command);
				free(parameter);
				_exit(127);
			}
			else if (IndEx == 2)
			{
				free(Command);
				free(parameter);
				_exit(126);
			}

		}

		free(Command);
	}
	free(parameter); /*valgrind*/
	_exit(0);
}
/**
 * wait_ - Function to Wait for the child process and evaluation Status
 * @argv: Command-Line arguments to print name exe shell
 * @Command: Input Command to Execute_
 * @Qex: Exec Quantity
 * Return: return 'Statuss' process
 **/
int wait_(char **argv, char *Command, int Qex)
{
	int Statuss;
	char **passedCommand;

	wait(&Statuss);
	if (WIFEXITED(Statuss))
	{
		passedCommand = parse_command(Command, " ");
		if (WEXITSTATUS(Statuss) == 126)
			_Errors(argv[0], passedCommand[0], PERM_DENIED, Qex);

		if (WEXITSTATUS(Statuss) == 127)
			_Errors(argv[0], passedCommand[0], NOT_FOUND, Qex);

		/** for uknown errors **/
		if (WEXITSTATUS(Statuss) != 127 &&
		    WEXITSTATUS(Statuss) != 126 &&
		    WEXITSTATUS(Statuss) != 2 &&
		    WEXITSTATUS(Statuss) != 0)
			perror("");

		free(passedCommand);
	}
return (WEXITSTATUS(Statuss));
}
