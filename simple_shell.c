#include "shell.h"

void Signalhandler(int sig);
void Write_DollarSign(void);
char **local_strtok(char *str);
unsigned int find_command(char *string);

/**
 * main - Entry function to the
 * simple shell project.
 * @argc: Int that represent the argument
 * passed lenght.
 * @argv: char array that contains all the
 * arguments passed.
 * @env: char array that contains all the
 * enviroment variables.
 * Return: 0 on Success, 1 if error happen.
 */
int main(int argc, char **argv, char **env)
{
    char *one = NULL, **two;
    size_t three = 0;
    ssize_t four;
    pid_t cid;
    int five, six = 0;
    (void)argc;

    Write_DollarSign();

    while ((four = getline(&one, &three, stdin)))
    {
        signal(SIGINT, Signalhandler);

        if (four == EOF)
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            free(buffer);
            exit(0);
            /*end_file(one);*/
        }
        else
        {
            six++;
            two = local_strtok(one);

            cid = fork();
            if (cid == -1)
            {
                perror("Error: Forking A Child Process");
                exit(EXIT_FAILURE);
                /*fork_fail();*/
            }
            else if (cid == 0)
            {
                printf("do some some");
                /*execute(two, one, env, argv, six);*/
            }
            else
            {
                wait(&five);
                /* send_to_free(one, two); */
            }
            three = 0;
            one = NULL;
            Write_DollarSign();
        }
    }

    if (four == -1)
    {
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/**
 * Signalhandler - This Function handles
 * signals and write the prompt.
 * @sig: signal to handle.
 * Return: Nothing (void).
 */
void Signalhandler(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * Write_DollarSign - This Function
 * prints the dollar sign.
 * Return: Nothing (void).
 *
 */
void Write_DollarSign(void)
{
    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    }
}

/**
 * find_command - find the number of commands in a string
 * @string: string that have the commands
 * Return: number of commands
 */
unsigned int find_command(char *string)
{
    unsigned int one = 0, two = 0, three = 0;

    while (string[one] != '\0')
    {
        if (string[one] != ' ')
        {
            three = 1;
        }
        if ((three && string[one + 1] == ' ') || (three && string[one + 1] == '\0'))
        {
            ++two;
            three = 0;
        }
        one++;
    }
    return (two);
}

/**
 * local_strtok - This Function create a
 * double pointer array that point to each string
 * from the command line.
 * @str: command from the terminal.
 * Return: array of pointers that are commands to interpret or execute.
 */
char **local_strtok(char *str)
{
    char *one, **two;
    unsigned int three;
    int four = 0;

    str[_strlen(str) - 1] = '\0';
    three = find_command(str);

    if (three == 0)
    {
        return (NULL);
    }
    else
    {
        two = malloc((sizeof(char *) * (three + 1)));

        if (two == NULL)
        {
            return (NULL);
        }
        else
        {
            one = strtok(str, " ");

            while (one != NULL)
            {
                two[four] = malloc(_strlen(one) + 1);
                if (two[four] == NULL)
                {
                    free_all_dp(two);
                    return (NULL);
                }
                else
                {
                    _strncpy(two[four], one, _strlen(one) + 1);
                    one = strtok(NULL, " ");
                    four++;
                }
            }
            two[four] = NULL;
            return (two);
        }
    }
}
