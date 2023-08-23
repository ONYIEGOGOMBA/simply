#include "shell.h"

/**
 * main- displays a prompt.
 * Return:0 always.
 */
int main(void)
{
	char *user_input = NULL;
	size_t input_size = 0;
	ssize_t input_length;
	char *env_variables[] = {NULL};

	while (1)
	{
		printf("simpleSimple$ ");
		input_length = getline(&user_input, &input_size, stdin);
		if (input_length == -1)
		{
			if (input_size > 0)
			{
				printf("\nexiting!\n");
			}
			break;
		}
		user_input[input_length - 1] = '\0';
		if (input_length > 1)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				char *command = user_input;

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
	}
	free(user_input);
	return (0);
}
