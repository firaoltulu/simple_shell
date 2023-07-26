#include "shell.h"

void custom_null_command(char *one);
void custom_get_out(char *one, char **two);
void custom_env_end(char *one, char **two, char **env);
void custom_print_env(char **two);

/**
<<<<<<< HEAD
 * Custom_execute - This Function perform verify
 * and execute every command.
 * @one: Char double pointer that
 * points to a command to perform.
 * @two: char pointer that points
 * to command in getline.
 * @env: char double pointer that
 * points to the environemet variable.
 * @three: char double pointer that
 * points to argument Counter.
 * @four: int that represents the
 * number of times that executed.
=======
 * custom__getenv - This Function gets the
 * value of global variable.
 * @one: char pointer that points to
 * the command of the global variable.
 * Return: char pointer pointing
 * string of value.
 */
char *custom__getenv(const char *one)
{
	int two;
	int three;
	char *four;

	if (!one)
	{
		return (NULL);
	}
	else
	{
		for (two = 0; environ[two]; two++)
		{
			three = 0;
			if (one[three] == environ[two][three])
			{
				while (one[three])
				{
					if (one[three] != environ[two][three])
					{
						break;
					}

					three++;
				}
				if (one[three] == '\0')
				{
					four = (environ[two] + three + 1);
					return (four);
				}
			}
		}
		return (0);
	}
}

/**
 * custom_linkpath - This function creates
 * a linked list for path directories.
 * @one: char pointer that points to
 * the string of path value
 * Return: pointer to the created linked list.
 */
custom_list *custom_linkpath(char *one)
{
	custom_list *two = '\0';
	char *three;
	char *four = _strdup(one);

	three = strtok(four, ":");
	while (three)
	{
		two = custom_add_node_end(&two, three);
		three = strtok(NULL, ":");
	}

	return (two);
}

/**
 * custom_add_node_end - this function adds a
 * new node at the end of a list_t list.
 * @one: custom_list double pointer that
 * points to our linked list.
 * @two: Char pointer that points to the
 * string in previous first node.
 * Return: address of the new element/node.
 */
custom_list *custom_add_node_end(custom_list **one, char *two)
{

	custom_list *three;
	custom_list *four;

	four = malloc(sizeof(custom_list));

	if (!four || !two)
	{
		return (NULL);
	}
	else
	{
		four->direct = two;
		four->point = '\0';

		if (!*one)
		{
			*one = four;
		}
		else
		{
			three = *one;

			while (three->point)
			{
				three = three->point;
			}

			three->point = four;
		}

		return (*one);
	}
}

/**
 * custom_which - This Function finds the pathcommand
 * of a filecommand.
 * @one: char pointer that points to the
 * command of file or command.
 * @two: custom_list pointer that points to the
 * head of linked list of path directories.
>>>>>>> 9207e756eede4b49eff9717a11bb42af5b7a59bd
 *
 * Return: Nothing(void).
 */
void Custom_execute(char **one, char *two, char **env, char **three, int four)
{
	struct stat fileStat;

	if (one == NULL)
	{
		custom_null_command(two);
	}
	else if (_strcmp("exit", one[0]))
	{
		custom_get_out(two, one);
	}
	else if (_strcmp("env", one[0]))
	{
		custom_env_end(two, one, env);
	}
	else if (stat(one[0], &fileStat) == 0)
	{
		execve(one[0], one, NULL);
	}
	else
	{
		custom_path(one, two, env, three, four);
	}
}

/**
 * custom_null_command - THis Function Free
 * the buffer that is created.
 * @one: char pointer that points to a buffer
 * taked from getline.
 *Return: Nothing(void).
 */
void custom_null_command(char *one)
{
	free(one);
	exit(EXIT_SUCCESS);
}

/**
 * custom_get_out - this function Free
 * the buffer and the commands taken from getline.
 * @one: char pointer that points
 * to a buffer taked from getline.
 * @two: char double pointer that
 * points to the command inserted.
 * Return: Nothing(void).
 */
void custom_get_out(char *one, char **two)
{
	unsigned int three = 0;

	free(one);

	if (two != NULL)
	{
		while (two[three])
		{
			free(two[three]);
			three++;
		}
		if (two[three] == NULL)
			free(two[three]);
		free(two);
	}
	exit(EXIT_SUCCESS);
}

/**
 * custom_env_end - this Function frees
 * the buffer and commands created in getline.
 * @one: Char pointer that points
 * to a buffer from getline.
 * @two: char double pointer that points to
 * an array store commands.
 * @env: char double pointer that points to
 * enviroment variables
 *
 * Return: Nothing(void).
 */
void custom_env_end(char *one, char **two, char **env)
{
	unsigned int three = 0;

	free(one);

	if (two != NULL)
	{
		while (two[three])
		{
			free(two[three]);
			three++;
		}
		if (two[three] == NULL)
			free(two[three]);
		free(two);
	}
	custom_print_env(env);
	exit(EXIT_SUCCESS);
}

/**
 * custom_print_env - THis Function prints
 * all enviroment variables.
 *
 * @two: char double pointer that points
 * to a enviroment variables for the user.
 *
 * Return: Nothing(void).
 */

void custom_print_env(char **two)
{
	unsigned int three = 0;
	unsigned int four;

	while (two[three])
	{
		four = _strlen(two[three]);
		write(STDOUT_FILENO, two[three], four);
		write(STDOUT_FILENO, "\n", 1);
		three++;
	}
}