#ifndef _MONTY_H_
#define _MONTY_H_
extern char *I1;
extern char *I2;
extern int i2;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void switching_fail(int n, const char *argv);
void push(stack_t **head, unsigned int n);
void pall(stack_t **head, unsigned int n);
int _isdigit(char *str);
int search_instruction(char *line);
void (*switching_instruction(stack_t **head, unsigned int l_count))(stack_t **, unsigned int);
void free_all(char *p1);
#endif
