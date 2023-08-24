#include "shell.h"
#include <errno.h>

/**
 * main- displays a prompt.
 * Return:0 always.
 */
int main(void)
{
	char *user_input = NULL;
	size_t input_size = 0;
	char *args[MAX_ARGS];
	int ten = isatty(0);

	while (1)
	{
		if (ten == 1)
		write(1, "$ ", 2);
		/*printf("#simpleShell$ ");*/
		display_prompt(&user_input, &input_size);
		if (user_input == NULL)
		{
			break;
		}
		if (strlen(user_input) > 0)
		{
			parseArguments(user_input, args);
			execute_prompt(user_input);
		}
	}
	free(user_input);
	return (0);
}
/**
 * display_prompt -reads and processes user input.
 * @user_input:a pointer to a pointer to a character.
 * @input_size:a pointer to a size_t variable.
 */

void display_prompt(char **user_input, size_t *input_size)
{
	ssize_t input_length;

	input_length = getline(user_input, input_size, stdin);
	if (input_length == -1)
	{
		if (*input_size > 0)
		{
			printf("\nexiting!\n");
		}
		free(*user_input);
		*user_input = NULL;
	}
	else
	{
		(*user_input)[input_length - 1] = '\0';
	}
}
/**
 * execute_prompt - a function that created a child process.
 * @command:the command to be executed.
 */

void execute_prompt(char *command)
{
	char *env_variables[] = {NULL};
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **argv = (char **)malloc(2 * sizeof(char *));

		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, env_variables) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(argv);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * parseArguments- a function that splits the
 * input into an array of arguments.
 * @input: function input.
 * @args:arguments.
 */
void parseArguments(char *input, char **args)
{
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
