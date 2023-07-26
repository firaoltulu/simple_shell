#include "shell.h"

/**
 * _strncpy - Function that copies a string into other
 *@dest: destination of the string
 *@src: string to copy
 *@n: length of the string
 *Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int four = 0;

	for (; four < n && src[four] != '\0'; four++)
		dest[four] = src[four];

	while (four < n)
	{
		dest[four] = '\0';
		four++;
	}

	return (dest);
}

/**
 * _strlen - THis Function gives
 * the length of a string.
 * @one: char pointer that points
 * to the string.
 * Return: int that represent
 * the length of string.
 *
 */
unsigned int _strlen(char *s)
{
	unsigned int two;

	two = 0;
	while (*s != '\0')
	{
		two++;
		s++;
	}

	return (two);
}

/**
 * _strcmp - Function to compare 2 strings
 * and find if are equal.
 * @s1: first string to compare.
 * @s2: second string to compare.
 * Return: 1 for equal, 0 if not.
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int two = 0;

	while (s1[two] != '\0')
	{
		if (s1[two] != s2[two])
		{
			return (0);
		}
		else
		{
			two++;
		}
	}

	return (1);
}