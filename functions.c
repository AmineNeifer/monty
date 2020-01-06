#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"
char *I1, *I2;
int i2;
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
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
	return (1);
}
/**
 *
 *
 *
 */
void (*switching_instruction)(stack_t **head, unsigned int l_count)
{
	instruction_t tab[3];
		tab[0] = {"push", push(head, l_count)};
		tab[1] = {"pall", pall(head, l_count)};
		tab[2] = {NULL, NULL};
	int i = 0;
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
					i2 = atoi(I2);
			}
			tab[i].f;
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", l_count, I1);
	exit(EXIT_FAILURE);
}

