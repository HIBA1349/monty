#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}


/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}


/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}



/**
 * _add - Adds the top two values of a stack_t linked list.
 * @doubly: head of the linked list
 * @cline: line number
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - doesn't do anything
 * @doubly: linked list head
 * @cline: line number
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
/**
 * _sub - Subtracts 2nd value from the top of stack_t linked list by top value.
 * @head: the head node
 * @cline: the line number
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void _sub(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	_pop(head, cline);
}

/**
 *_div -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */

void _div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 *_mul -Multiplies 2nd value from the top of stack_t linked list by top value.
 * @head: the head node
 * @cline: the line number
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void _mul(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	_pop(head, cline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 * info:The result is stored in 2nd value node from the top
 * and top value removed.
 */

void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 * _pchar - print the char value of the first element
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}


/**
 * _rotl - rotates 1st element to the bottom and 2nd to the top
 * @doubly: linked list head
 * @cline: line nummber
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * _rotr - reverse stack
 * @doubly: linked list head
 * @cline: line number
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux = *doubly;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}

/**
 * _queue - sets format of data to queue(FIFI/LILO)
 * @doubly: head of linked list
 * @cline: line number
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - sets format of data to stack (LIFO/FILO)
 * @doubly: linked list head
 * @cline: line number
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}
