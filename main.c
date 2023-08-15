#include "shell.h"
/**
 * main - main function.
 * void: doesn't take in arguments.
 * Return: 0.
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		printf("#simpleshell$ ");
		fflush(stdout);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		display_prompt(input);
	}
	return (0);
}
