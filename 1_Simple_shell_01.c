#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

extern char **environ;

/**
 * main - Entry point
 * Description: A simple UNIX command line interpreter using execve.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *argv[] = {NULL, NULL};
	int status;

	while (1)
	{
		/* Display a prompt */
		printf("$ ");
		fflush(stdout);

		/* Handle EOF condition */
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		/* Remove the newline character */
		size_t length = strlen(command);

		if (command[length - 1] == '\n')
		{
			command[length - 1] = '\0';
		}

		argv[0] = command;

		/* Execute the command using execve */
		if (execve(command, argv, environ) == -1)
		{
			perror("Error");
		}
	}

	return (0);
}
