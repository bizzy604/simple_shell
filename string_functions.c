#include "shell.h"

/**
 * String_copy -Function that copies the string pointed to by src,
 * @dest: Pointer Var to copy string to
 * @src: Pointer variable for string to be copied
 * Return: dest
 */
char *String_copy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * String_char - Function that locates a character in a pointer to string
 * @s: pointer to the string being searched
 * @c: second string
 * Return: a pointer to the first occurrence of char c in the string s
 * or NULL if character is not found
 */
char *String_char(char *s, char c)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
	{
		if (s[counter] == c)
			return (s + counter);
	}
	if (s[counter] == c)
		return (s + counter);
	return (0);
}

/**
 * String_conc - Function that concatenates two strings
 * @dest: Destination pointer var for string to be concetenated to
 * @src: Source pointer var of the string to be concatenated
 * Return: dest
 */
char *String_conc(char *dest, char *src)
{
	int i = 0, j;

	while (*(dest + i))
	{
		i++;
	}
	for (j = 0; *(src + j); j++, i++)
	{
		*(dest + i) = *(src + j);
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * String_dupl - Function to allocate space in memory and return pointer
 * which contains to copy of the string given as a parameter
 * @str: string
 * Return: Pointer to the copy, NULL if it fails
 */
char *String_dupl(char *str)
{
	int counter_1, counter_2, counter_3;
	char *Fund_Up;

	if (str == 0)
		return (NULL);

	for (counter_1 = 0; str[counter_1] != '\0'; counter_1++)
		;
	counter_2 = counter_1;

	Fund_Up = malloc(sizeof(char) * counter_2 + 1);
	if (Fund_Up == 0)
		return (NULL);

	for (counter_3 = 0; counter_3 < counter_2; counter_3++)
		Fund_Up[counter_3] = str[counter_3];
	Fund_Up[counter_2] = str[counter_2];

	return (Fund_Up);
}
