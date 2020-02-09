#include "monty.h"
#include <stdlib.h>
#include <stdio.h> 
void push(stack_t **head, unsigned int n)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		switching_fail(0, NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	(*head) = new;
}
void pall(stack_t **head, unsigned int n)
{
	stack_t *p;
	(void)(n);

	p = *head;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

