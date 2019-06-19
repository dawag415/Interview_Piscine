#include "header.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct s_stack *initStack(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

int pop(struct s_stack *stack)
{
	if (!stack->item)
		return (-1);

	struct s_item *head = stack->item;
	stack->item = stack->item->next;

	return (head->idx);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *new_head = malloc(sizeof(struct s_item));

	new_head->idx = idx;
	new_head->next = stack->item;
	stack->item = new_head;
}

char *console(void)
{
	size_t bufsize = 10;
	char *message = (char*)malloc(sizeof(char) * MAX_LENGTH + 1);
	memset(message, 0, MAX_LENGTH + 1);
	int i = 0;

	struct s_stack *stack = initStack();

	while(1)
	{
		ssize_t size = 0;
		char *entry = NULL;
		printf("ENTER MESSAGE:");
		size = getline(&entry, &bufsize, stdin);
		if (size <= 0)
			exit(1);
		else
			entry[--size] = 0;

		if (strcmp(entry, "SEND") == 0)
			break ;

		if (i > 0)
		{
			strcat(message, " ");
			i++;
		}
		if (strcmp(entry, "UNDO") != 0)
		{
			push(stack, i);
			strcat(message, entry);
			i += size;
		}
		else
		{
			i = pop(stack);
			if (i < 0)
				i = 0;
			message[i] = 0;
		}

		printf("%s\n", message);
		free(entry);
		entry = NULL;
	}
	return (message);
}