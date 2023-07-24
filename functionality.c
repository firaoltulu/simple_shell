#include "shell.h"

void custom_null_command(char *one);
void custom_get_out(char *one, char **two);

/**
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
		printf("do some some one = %s\n", one[0]);
		custom_get_out(two, one);
	}
	else if (_strcmp("env", one[0]))
	{
		printf("do some some env = %s\n", env[0]);
		/*env_end(two, one, env);*/
	}
	else if (stat(one[0], &fileStat) == 0)
	{
		printf("do some some three = %s\n", three[0]);
		printf("do some some four = %d\n", four);
		/*execve(one[0], one, NULL);*/
	}
	else
	{
		/* _path(one, two, env, three, four);*/
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

	if (two == NULL)
	{
		return;
	}
	else
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
