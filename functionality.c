#include "shell.h"

custom_list *custom_add_node_end(custom_list **one, char *two);

/**
 * custom__getenv - This Function gets the
 * value of the global variable.
 * @one: char pointer that points to
 * the command of the global variable.
 * Return: char pointer that points to
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
 *
 * Return: char pointer that points to the
 * pathcommand of filecommand or NULL if no match.
 */
char *custom_which(char *one, custom_list *two)
{
	struct stat three;
	char *four;

	custom_list *five = two;

	while (five)
	{

		four = concat_all(five->direct, "/", one);
		if (stat(four, &three) == 0)
		{
			return (four);
		}
		free(four);
		five = five->point;
	}

	return (NULL);
}

/**
 * custom_check_build - This Function checks if the
 * command is a build in or not.
 * @arv: char double pointer that points to
 * the array of arguments.
 * Return: pointer to function that
 * takes arv and returns void.
 */
void (*custom_check_build(char **arv))(char **arv)
{
	int one, two;
	custom three[] = {
		{"exit", custom_build_exit},
		{"env", custom_build_env},
		{"setenv", custom_build_setenv},
		{"unsetenv", custom_build_unsetenv},
		{NULL, NULL}};

	for (one = 0; three[one].command; one++)
	{
		two = 0;
		if (three[one].command[two] == arv[0][two])
		{
			for (two = 0; arv[0][two]; two++)
			{
				if (three[one].command[two] != arv[0][two])
				{
					break;
				}
			}
			if (!arv[0][two])
			{
				return (three[one].func);
			}
		}
	}
	return (0);
}
