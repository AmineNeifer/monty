#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"
char *I1, *I2;
int main(int argc, char const *argv[])
{
	unsigned int l_count = 1;
	stack_t *head;
	FILE *fd;
	char *buffer;
	ssize_t test_getline = 0;
	size_t buffersize = 1024;
	void (*func)(stack_t **, unsigned int);

	head = NULL;
	if (argc != 2)
		switching_fail(2, NULL);
	fd = fopen(argv[1], "r");
	if (!fd)
		switching_fail(1, argv[1]);
	I1 = malloc(sizeof(char) * 20);
	if (!I1)
		switching_fail(0, NULL);
	I2 = malloc(sizeof(char) * 20);
	if (!I2)
	{
		free(I1);
		switching_fail(0, NULL);
	}
	buffer = malloc(sizeof(char) * buffersize);
	if (!buffer)
	{
		free(I1);
		free(I2);
		switching_fail(0, NULL);
	}
	while (test_getline != -1)
	{
		test_getline = getline(&buffer, &buffersize, fd);
		if (test_getline == EOF)
			break;
		if (search_instruction(buffer) == -1)
		{
			free_all(buffer);
			switching_fail(0, NULL);
		}
		func = switching_instruction(&head, l_count);
		func(&head, l_count);
		l_count++;
	}
	free_all(buffer);
	fclose(fd);
	return (0);
}
