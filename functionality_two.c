#include "shell.h"

char **get_env_variables_key_pair(char *one, char **two);
char *custom__getenv(char *one, char **env);
unsigned int custom_find_num_dir(char *one);
char *custom__strncp(char *dest, char *src, char *command, int n, int c);
void print_error_message(char **one, char *two, int count);
int custom_puterror(char one);

/**
 * custom_path - This Function checks
 * and executes the command inserted.
 * @one: char double pointer that
 * points to an array stored commands
 * @two: char pointer that points to
 * a buffer from getline.
 * @env: char double pointer that
 * points to an enviroment variables.
 * @argv: char double pointer that
 * points to an argument vector.
 * @count: Int that represent  a number
 * of times runned the prompt.
 * Return: Nothing(Void).
 */
void custom_path(char **one, char *two, char **env, char **argv, int count)
{
	struct stat fileStat2;
	int three = 0;
	char **four;
	unsigned int i = 0;

	four = get_env_variables_key_pair(one[0], env);
	while (four[three])
	{
		if (stat(four[three], &fileStat2) == 0)
		{
			execve(four[three], one, NULL);
		}
		three++;
	}

	print_error_message(argv, one[0], count);

	free(two);

	if (one != NULL)
	{
		while (one[i])
		{
			free(one[i]);
			i++;
		}
	}

	i = 0;

	if (four != NULL)
	{
		while (four[i])
		{
			free(four[i]);
			i++;
		}
	}

	exit(EXIT_SUCCESS);
}

/**
 * get_env_variables_key_pair - THis Function creates
 * a double pointer array, where stores
 * each path five as a pointer.
 * @one: char pointer that points to the
 * first command inserted in the prompt
 * @two: char double pointer that points
 * to enviroment variables.
 * Return: char double pointer that points to
 * the all the enviroment key-pair.
 */
char **get_env_variables_key_pair(char *one, char **two)
{
	char **three;
	char *four;
	char *five;
	unsigned int length;
	unsigned int six = 0;
	int seven;
	int eight;

	four = custom__getenv("PATH", two);
	length = custom_find_num_dir(four);
	three = malloc(sizeof(char *) * (length + 1));

	if (three == NULL)
	{
		return (NULL);
	}
	else
	{
		five = strtok(four, ":");

		while (five != NULL)
		{
			seven = _strlen(five);
			eight = _strlen(one);
			three[six] = malloc(sizeof(char *) * (seven + eight + 2));
			if (three[six] == NULL)
			{
				unsigned int i = 0;

				if (three != NULL)
				{
					while (three[i])
					{
						free(three[i]);
						i++;
					}
				}
				return (NULL);
			}
			else
			{
				custom__strncp(three[six], five, one, seven, eight);
				six++;
				five = strtok(NULL, ":");
			}
		}

		three[six] = NULL;

		return (three);
	}
}

/**
 * custom__getenv - THis Function get
 * the enviroment variable.
 * @one: char pointer that points to
 * a name of the enviroment variable.
 * @env: char double pointer that
 * points to the enviroment variables.
 * Return: char pointer that points to
 * the value associated with the variable.
 */
char *custom__getenv(char *one, char **env)
{
	char *two;
	char *three;
	unsigned int four = 0;
	unsigned int five;

	five = _strlen(one);

	three = malloc(sizeof(char) * five + 1);

	if (three == NULL)
	{
		return (NULL);
	}
	else
	{
		_strncpy(three, one, five);

		two = strtok(env[four], "=");
		while (env[four])
		{
			if (_strcmp(two, three))
			{
				two = strtok(NULL, "\n");
				free(three);
				return (two);
			}
			four++;
			two = strtok(env[four], "=");
		}
		free(three);
		return (NULL);
	}
}

/**
 * custom_find_num_dir - THis Function finds
 * the total number of directories.
 * @one: Char pointer that points to
 * the path string.
 * Return: Integer that represents the
 * number of directories in the path.
 */
unsigned int custom_find_num_dir(char *one)
{
	unsigned int two = 0;
	unsigned int three = 0;
	unsigned int four = 0;

	while (one[two])
	{
		if (one[two] != ':')
		{
			three = 1;
		}
		if ((three && one[two + 1] == ':') || (three && one[two + 1] == '\0'))
		{
			four++;
			three = 0;
		}
		two++;
	}

	return (four);
}

/**
 * custom__strncp - This Function copies
 * the path and append a / and command.
 * @dest: Char pointer that points to the
 * destination to save.
 * @src: Char pointer that points to the
 * source.
 * @command: Char pointer that points to the
 * command to append.
 * @n: int that represents the length of destination.
 * @c: int that represents the length of command.
 *
 * Return: Char pointer that points to the
 * address of dest.
 */
char *custom__strncp(char *dest, char *src, char *command, int n, int c)
{
	int one;
	int two;

	for (one = 0; one < n && src[one] != '\0'; one++)
	{
		dest[one] = src[one];
	}

	dest[one] = '/';
	one++;

	for (two = 0; two < c && command[two] != '\0'; two++, one++)
	{
		dest[one] = command[two];
	}
	dest[one] = '\0';
	return (dest);
}

/**
 * print_error_message - THis Function writes
 * an error message.
 * @one: char double pointer that points to a
 * argument vector.
 * @two: char pointer that points to a
 * first command to print if not found.
 * @count: integer that represent a number
 * of times to executed.
 * Return: Nothing(void).
 */
void print_error_message(char **one, char *two, int count)
{
	int three = 1;
	int four;
	int five = 1;

	write(STDERR_FILENO, one[0], _strlen(one[0]));
	write(STDERR_FILENO, ": ", 2);
	four = count;

	while (four >= 10)
	{
		four /= 10;
		five *= 10;
		three++;
	}

	while (three > 1)
	{
		if ((count / five) < 10)
		{

			custom_puterror((count / five + '0'));
		}
		else
		{
			custom_puterror((count / five) % 10 + '0');
		}
		--three;
		five /= 10;
	}

	custom_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, two, _strlen(two));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * custom_puterror - This Function Prints a char.
 * @one: character to write.
 * Return: int to represent success or failor.
 */
int custom_puterror(char one)
{
	return (write(STDERR_FILENO, &one, 1));
}
