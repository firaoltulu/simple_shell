#include "shell.h"

void cutom_handler_exit(int one);
void cutom_EOF(int one, char *two);
void print_new_line(void);
char **custom_splitstring(char *one, const char *two);
void custom_execute(char **one);

/**
 * main - Main Function.
 *
 * Return: Int 0 on success.
 */
int main(void)
{
	ssize_t one = 0;
	char *two = NULL;
	char *three;
	char *four;
	char **five;
	size_t six = 0;
	custom_list *seven = '\0';
	void (*nine)(char **);
	custom_list *storage;

	signal(SIGINT, cutom_handler_exit);

	while (one != EOF)
	{
		print_new_line();
		one = getline(&two, &six, stdin);
		cutom_EOF(one, two);
		five = custom_splitstring(two, " \n");

		if (!five || !five[0])
		{
			custom_execute(five);
		}
		else
		{
			three = custom__getenv("PATH");
			seven = custom_linkpath(three);
			four = custom_which(five[0], seven);
			nine = custom_check_build(five);
			if (nine)
			{
				free(two);
				nine(five);
			}
			else if (!four)
			{
				custom_execute(five);
			}
			else if (four)
			{
				free(five[0]);
				five[0] = four;
				custom_execute(five);
			}
		}
	}

	while (seven)
	{
		storage = seven->point;
		free(seven->direct);
		free(seven);
		seven = storage;
	}

	custom_free_arv(five);
	free(two);
	return (0);
}

/**
 *
 * cutom_handler_exit - THis function
 * checks if Ctrl C is pressed or not.
 * @one: int that represent the
 * signal.
 * Return: Nothing(Void).
 */
void cutom_handler_exit(int one)
{
	if (one == SIGINT)
	{
		_puts("\n$ ");
	}
}

/**
 * cutom_EOF - This Function handles
 * the End of File.
 * @one: Int that Represent
 * the return value of getline function.
 * @two: char pointer that
 * points to the buffer.
 *
 * Return: Nothing(Void).
 */
void cutom_EOF(int one, char *two)
{
	(void)two;
	if (one == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(two);
		}
		exit(0);
	}
}

/**
 * print_new_line - THis Function verifiy
 * if its the terminal or Another.
 * Return: Nothing(Void).
 */
void print_new_line(void)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("$ ");
	}
}

/**
 * custom_splitstring - This Function splits a string
 * and makes it an array of pointers to words.
 * @one: Char Pointer THat points to the string
 * to be split.
 * @two: Char Pointer THat points to the delimiter.
 *
 * Return: char double pointer that points to the
 * array of pointers to words.
 */
char **custom_splitstring(char *one, const char *two)
{

	int three;
	int four;
	char **five;
	char *six;
	char *seven;

	seven = malloc(_strlen(one) + 1);
	if (seven == NULL)
	{
		perror(custom__getenv("_"));
		return (NULL);
	}
	else
	{
		three = 0;
		while (one[three])
		{
			seven[three] = one[three];
			three++;
		}
		seven[three] = '\0';

		six = strtok(seven, two);
		five = malloc((sizeof(char *) * 2));
		five[0] = _strdup(six);

		three = 1;
		four = 3;
		while (six)
		{
			six = strtok(NULL, two);
			five = custom__reallocate(five, (sizeof(char *) * (four - 1)), (sizeof(char *) * four));
			five[three] = _strdup(six);
			three++;
			four++;
		}
		free(seven);
		return (five);
	}
}

/**
 * custom_execute - this function custom_executes a command.
 *
 * @one: char double pointer that points
 * to the array of arguments.
 *
 * Return: Nothing(Void).
 */
void custom_execute(char **one)
{

	int two, three;

	if (!one || !one[0])
	{
		return;
	}
	else
	{
		two = fork();
		if (two == -1)
		{
			perror(custom__getenv("_"));
		}
		if (two == 0)
		{
			execve(one[0], one, environ);
			perror(one[0]);
			exit(EXIT_FAILURE);
		}
		wait(&three);
	}
}
