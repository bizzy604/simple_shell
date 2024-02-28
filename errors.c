#include "shell.h"
/**
 * Errors- Function to print error to stderr
 *@program : pointer to program
 *@param: char pointer to the Passed command
 *@message: Description erorr to be printed
 *@Qexe: No of executions Executions
 **/
void Errors(char *program, char *param, char *message, int Qexe)
{

	char buf[256];
	char sint[11];

	IntegerToString(Qexe, sint);

	String_copy(buf, program);
	String_conc(buf, ": ");
	String_conc(buf, sint);
	String_conc(buf, ": ");
	String_conc(buf, param);
	String_conc(buf, ": ");
	String_conc(buf, message);
	String_conc(buf, "\n");

	write(STDERR_FILENO, &buf, _String_Length(buf));

}
