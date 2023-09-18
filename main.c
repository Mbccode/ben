#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on succes
 */
int main(void)
{
	char *prompt = "$ ";
	char *_get = NULL, *tok;
	ssize_t getRV;
	size_t nget = 0;

	write(STDOUT_FILENO, prompt, strlen(prompt));
	getRV = _getline(&_get, &nget, stdin);

	if (getRV == -1)
	{
		perror("Error");
		free(_get);
		exit(EXIT_FAILURE);
	}
	if (_get[getRV - 1] == '\n')
		_get[getRV - 1] = '\0';

	printf("%s was gotten from CMD\n", _get);
	printf("%lu\n", nget);
	printf("%lu\n", strlen(_get));
	
	tok = _strtok(_get, " ");
	while (tok != NULL)
	{
		printf("%s\n", tok);
		tok = _strtok(NULL, " ");
	}

	free(_get);
	return (0);
}
