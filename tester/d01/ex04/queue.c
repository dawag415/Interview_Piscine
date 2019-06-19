#include "header.h"
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	char *head = NULL;

	if (queue->first == NULL)
		return (NULL);
	head = queue->first->message;
	struct s_node *tmp = queue->first;
	free(tmp);
	tmp = NULL;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	return (head);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new_head = malloc(sizeof(struct s_node));
	new_head->message = strdup(message);
	new_head->next = queue->first;
	queue->first = new_head;
	if (queue->last == NULL)
		queue->last = new_head;
}

char *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}
