#include "header.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (!stack->item)
		return (NULL);

	struct s_item *head = stack->item;
	stack->item = stack->item->next;

	return (head);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new_head = malloc(sizeof(struct s_item));

	new_head->word = strdup(word);
	new_head->next = stack->item;
	stack->item = new_head;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack = stackInit();
	struct s_node *temp = lst;
	struct s_item *head = NULL;

	while(temp)
	{
		push(stack, temp->word);
		temp = temp->next;
	}
	while ((head = pop(stack)))
	{	printf("%s", head->word);
		if(head->next)
			printf(" ");
	}
	printf("\n");
}
