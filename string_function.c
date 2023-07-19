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
 * _strlen - Function to find the
 * length of a string.
 * @s: string to calculate the length.
 * Return: the length of the string.
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
	int five = 0;

	while (s1[five] != '\0' && s2[five] != '\0')
	{
		if (s1[five] != s2[five])
		{
			return (s1[five] - s2[five]);
		}
		five++;
	}
	return (0);
}
