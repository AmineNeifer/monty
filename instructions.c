#include "monty.h"
#include <stdlib.h>
#include <stdio.h> 
char *I1, *I2;
int i2;
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
	(void)(n);
	stack_t *p;
	
	p = *head;
	printf("just entered pall\n");
	while (p != NULL)
	{
		printf("bjeh raby h->n %d\n", p->n);
		p = p->next;
	}
}
 
