#include "shell.h"
/**
 * removeSpaces- Function to remove spaces for the string
 * @str:  Input strng to remove spaces for
 * Return: void
 **/

void removeSpaces(char *str)
{
	size_t Len_Of_String = _String_Length(str);
	char Return[512];
	size_t b = 0;
	size_t a = 0;

	for (a = 0; a < Len_Of_String; ++a)
	{
		if (str[a] != ' ')
		{
			Return[b] = str[a];
			b++;
		}
	}
	if (b < Len_Of_String)
		str[b] = '\0';

	for (a = 0; a < b; ++a)
	{
		str[a] = Return[a];
	}
}

