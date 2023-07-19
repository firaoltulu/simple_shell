#include "shell.h"
/**
 * free_all_dp - frees all the memory including a double pointer
 * @ptr: pointer to free
 * Return: Nothing
 */

/*void free_all_dp(char **ptr)
{
    unsigned int i = 0;

    if (ptr == NULL)
        return;

    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }

    if (ptr[i] == NULL)
        free(ptr[i]);
    free(ptr);
}*/

/**
 * parent_free_commands - free the buffer and the commands
 * @buffer: buffer in getline
 * @ptr: double pointer that store all the commands inserted
 * Return: Nothing(void)
 */

void parent_free_commands(char *buffer, char **ptr)
{
    free(buffer);
    /*free_all_dp(commands);*/
    unsigned int i = 0;
    if (ptr == NULL)
        return;

    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }

    if (ptr[i] == NULL)
        free(ptr[i]);
    free(ptr);
}

/**
 * send_to_free - This Function frees memory
 * when the child is not created.
 * @one: char pointer that points to
 * a buffer created by getline.
 * @two: char array that contains commands.
 *
 * Return: Nothing(void).
 */

void send_to_free(char *one, char **two)
{
    if (two == NULL)
    {
        parent_free_commands(one, two);
    }
    else if (_strcmp("exit", two[0]))
    {
        /**get_out(one, two);*/
    }
    else
    {
        parent_free_commands(one, two);
    }
}
