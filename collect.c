#include "shell.h"

void Custom_get_out(char *one, char **three);

/**
 * custom_parent_free_commands - This Function free
 * the buffer and the commands.
 * @one: char pointer that points
 * to a buffer in getline.
 * @three: char double pointer that store
 * all the commands inserted.
 * Return: Nothing(void)
 */
void custom_parent_free_commands(char *one, char **three)
{
    int two = 0;

    free(one);

    if (three != NULL)
    {
        while (three[two])
        {
            free(three[two]);
            two++;
        }

        if (three[two] == NULL)
            free(three[two]);
        free(three);
    }
}

/**
 * Custom_send_to_free - This Function frees memory
 * when the child is not created.
 * @one: char pointer that points to
 * a buffer created by getline.
 * @two: char array that contains commands.
 *
 * Return: Nothing(void).
 */
void Custom_send_to_free(char *one, char **two)
{
    if (two == NULL)
    {
        custom_parent_free_commands(one, two);
    }
    else if (_strcmp("exit", two[0]))
    {
        Custom_get_out(one, two);
    }
    else
    {
        custom_parent_free_commands(one, two);
    }
}

/**
 * Custom_get_out - this Function Free
 * the buffer.
 * and commands taken from getline.
 * @one: char pointer that points to
 * buffer taked from getline.
 * @three: Char double Pointer that points
 * to a command to inserted.
 * Return: Nothing(void).
 */
void Custom_get_out(char *one, char **three)
{
    int two = 0;
    free(one);
    /*free_all_dp(commands);*/
    if (three != NULL)
    {
        while (three[two])
        {
            free(three[two]);
            two++;
        }
        if (three[two] == NULL)
            free(three[two]);
        free(three);
    }
    exit(EXIT_SUCCESS);
}