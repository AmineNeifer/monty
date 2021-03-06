#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"
/**
 * search_instruction - searches for opcode and its argument
 * @line: line we're treating from the *.m file
 * Return: -1 if there's an Error, otherwise 0.
 */
int search_instruction(char *line)
{
	char *token;

	token = malloc(20 * sizeof(char));
	if (token == NULL)
	{
		return (-1);
	}
	token = strtok(line, " \n");
	if (token)
	{
		strcpy (I1, token);
		token = strtok(NULL, " \n\t");
	}
	if (token)
	{
		strcpy (I2, token);
	}
	return (0);
}
/**
 * switching_fail - handles the malloc fail.
 * @n: 0: malloc fail, 1: open file fail, 2: agrc != 2.
 * Return: N/A.
 */
void switching_fail(int n, const char *argv)
{
	switch (n)
	{
		case 0:
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
			break;
		case 1:
			dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
			exit(EXIT_FAILURE);
			break;
		case 2:
			dprintf(STDERR_FILENO, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
	}
}
/**
 * _isdigit - checks if string is all digits
 * @str: string to check
 * Return: 1 if str is from digits otherwise 0.
 */
int _isdigit(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
	{
		if (strcmp(str, "") || str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 *
 *
 *
 */
void (*switching_instruction(stack_t **head, unsigned int l_count))(stack_t **, unsigned int)
{
	instruction_t tab[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;
	(void)head;
	while (tab[i].opcode)
	{
		if (strcmp(tab[i].opcode, I1) == 0)
		{
			if (i == 0)
			{
				if (_isdigit(I2) == 0)
				{
					dprintf(2, "L%d: usage: push integer\n", l_count);
					exit(EXIT_FAILURE);
				}
				else
				{
					return (tab[i].f);
				}
			}
			return (tab[i].f);
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", l_count, I1);
	exit(EXIT_FAILURE);
}
/**
 * free_all - free's all malloced pointers.
 *
 * @p1: first pointer.
 * @p2: second pointer.
 * @p3: third pointer.
 */
void free_all(char *p1)
{
	char *array[3];
	int i;

	array[0] = p1;
	array[1] = I1;
	array[2] = I2;

	for (i = 0; i < 3; i++)
	{
		if (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
		}
	}
}
