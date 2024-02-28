#include "shell.h"
/**
 * Atoi - Function program to Convert a string to an integer
 * @s: the string to be converted
 * Return: Converted integer
 */
int Atoi(char *s)
{
int i, begin, neg;
unsigned int number;

begin = -1;
neg = 0;
number = 0;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
begin = i;
if (s[i] == '-' && begin == -1)
{
if (neg)
neg = 0;
else
neg = 1;
}
}
if (begin != -1)
{
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
number = number * 10 + s[i] - '0';
else if (s[i - 1] >= '0' && s[i - 1] <= '9')
break;
}
}
if ((number >= (unsigned int) INT_MAX && neg == 0))
return (INT_MAX);
else if ((number > (unsigned int) INT_MAX && neg))
return (INT_MIN);
else if (neg)
return ((int) -number);
else
return ((int) number);
}
