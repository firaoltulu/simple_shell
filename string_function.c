#include "shell.h"

/**
 * concat_all - This Function concatinates
 * three strings in a newly allocated memory.
 * @one: char pointer that
 * points the first string.
 * @two: char pointer that
 * points the second string.
 * @three: char pointer that
 * points the Third string.
 * Return: char pointer that
 * points to the new string.
 */
char *concat_all(char *one, char *two, char *three)
{
	char *four;
	int five, six, seven, eight, nine;

	five = _strlen(one);
	six = _strlen(two);
	seven = _strlen(three);

	four = malloc(five + six + seven + 1);
	if (!four)
	{
		return (NULL);
	}
	else
	{

		for (eight = 0; one[eight]; eight++)
		{
			four[eight] = one[eight];
		}
		nine = eight;

		for (eight = 0; two[eight]; eight++)
		{
			four[nine + eight] = two[eight];
		}
		nine = nine + eight;

		for (eight = 0; three[eight]; eight++)
		{
			four[nine + eight] = three[eight];
		}
		nine = nine + eight;

		four[nine] = '\0';
		return (four);
	}
}

/**
 * custom__reallocate - This Function Reallocates memory block.
 * @one: void pointer that points to
 * the previous pointer.
 * @two: int that represent the old
 * size of previous pointer.
 * @three: int that represent the new
 * size for our pointer.
 * Return: void pointer that points to the
 * New resized Pointer.
 */
void *custom__reallocate(void *one, unsigned int two, unsigned int three)
{
	unsigned int six;
	char *four;
	char *five;

	if (one == NULL)
	{
		return (malloc(three)); }
	if (three == two)
	{
		return (one); }
	if (three == 0 && one != NULL)
	{
		free(one);
		return (NULL); }

	four = malloc(three);
	five = one;
	if (four == NULL)
	{
		return (NULL);
	}
	else
	{
		if (three > two)
		{
			for (six = 0; six < two; six++)
			{
				four[six] = five[six]; }
			free(one);
			for (six = two; six < three; six++)
			{
				four[six] = '\0'; }
		}
		if (three < two)
		{
			for (six = 0; six < three; six++)
			{
				four[six] = five[six]; }
			free(one); }
		return (four); }
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
int _strlen(char *one)
{
	int two = 0;

	while (*(one + two) != '\0')
	{
		two++;
	}
	return (two);
}

/**
 * _putchar - this function writes
 * the character c to stdout.
 * @c: char that holds The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strdup - This Function returns a pointer
 * to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @one: char pointer that points to string.
 * Return: char pointer that points to string.
 */
char *_strdup(char *one)
{
	int two;
	int three;
	char *new;

	if (!one)
	{
		return (NULL);
	}
	else
	{
		for (three = 0; one[three] != '\0';)
		{
			three++;
		}
		new = malloc(sizeof(char) * three + 1);
		if (!new)
		{
			return (NULL);
		}
		for (two = 0; two < three; two++)
		{
			new[two] = one[two];
		}
		new[three] = one[three];
		return (new);
	}
}

/**
 * _puts - this function prints a string.
 * @one: pointer to string.
 * return: Nothing(Void);
 */
void _puts(char *one)
{
	int two = 0;

	while (one[two])
	{
		_putchar(one[two]);
		two++;
	}
}
