#include "shell.h"

/**
 * custom__atoi - This custom Function converts
 * a string into an integer.
 * @one: char pointer that points
 * to a string.
 * Return: Integer.
 */
int custom__atoi(char *one)
{
	int two = 0;
	int three = 0;
	int four = 1;

	while (!((one[two] >= '0') && (one[two] <= '9')) && (one[two] != '\0'))
	{
		if (one[two] == '-')
		{
			four = four * (-1);
		}
		two++;
	}
	while ((one[two] >= '0') && (one[two] <= '9'))
	{
		three = (three * 10) + (four * (one[two] - '0'));
		two++;
	}

	return (three);
}

/**
 * custom_build_exit - This Function exits
 * the shell with or without a
 * return of status n.
 *
 * @one: char double pointer that points
 * to the array of words of the entered line.
 *
 * Return: Nothing(Void).
 */
void custom_build_exit(char **one)
{
	int two, three;

	if (one[1])
	{

		three = custom__atoi(one[1]);
		if (three <= -1)
		{
			three = 2;
		}
		custom_free_arv(one);
		exit(three);
	}
	for (two = 0; one[two]; two++)
	{
		free(one[two]);
	}
	free(one);
	exit(0);
}

/**
 * custom_free_arv - This Function frees
 * the array of pointers arv.
 * @one: char double pointer that
 * points to the array of pointers.
 *
 * Return: Nothing(Void).
 */
void custom_free_arv(char **one)
{
	int two;

	for (two = 0; one[two]; two++)
	{
		free(one[two]);
	}
	free(one);
}
/**
 * custom_build_env - This Function prints
 * the current environment.
 * @one: Char pointer that points
 * to the array of arguments.
 * Return: Nothing(Void).
 */
void custom_build_env(char **one __attribute__((unused)))
{
	int two;

	for (two = 0; environ[two]; two++)
	{
		_puts(environ[two]);
		_puts("\n");
	}
}

/**
 * custom_build_setenv - this function Initialize a
 * new environment variable, or modify
 * an existing one.
 * @one: char double pointer that points to the
 * array of entered words.
 * Return: Nothing(Void)
 */
void custom_build_setenv(char **one)
{
	int two, three, four;

	if (!one[1] || !one[2])
	{
		perror(custom__getenv("_"));
		return;
	}
	else
	{
		for (two = 0; environ[two]; two++)
		{
			three = 0;
			if (one[1][three] == environ[two][three])
			{
				while (one[1][three])
				{
					if (one[1][three] != environ[two][three])
					{
						break; }
					three++; }
				if (one[1][three] == '\0')
				{
					four = 0;
					while (one[2][four])
					{
						environ[two][three + 1 + four] = one[2][four];
						four++; }
					environ[two][three + 1 + four] = '\0';
					return; }
			}
		}

		if (!environ[two])
		{

			environ[two] = concat_all(one[1], "=", one[2]);
			environ[two + 1] = '\0';
		}
	}
}

/**
 * custom_build_unsetenv - This function Remove
 * an environment variable.
 * @one: char double pointer that points to the
 * array of entered words.
 * Return: Nothing(Void).
 */
void custom_build_unsetenv(char **one)
{
	int two, six;

	if (!one[1])
	{
		perror(custom__getenv("_"));
		return;
	}
	else
	{
		for (two = 0; environ[two]; two++)
		{
			six = 0;
			if (one[1][six] == environ[two][six])
			{
				while (one[1][six])
				{
					if (one[1][six] != environ[two][six])
					{
						break;
					}
					six++;
				}
				if (one[1][six] == '\0')
				{
					free(environ[two]);
					environ[two] = environ[two + 1];
					while (environ[two])
					{
						environ[two] = environ[two + 1];
						two++;
					}
					return;
				}
			}
		}
	}
}
