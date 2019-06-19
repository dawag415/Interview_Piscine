#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *queue = queueInit();
	printf("is empty? %d\n", isEmpty(queue));
	printf("peek %s\n", peek(queue));
	enqueue(queue, "1");
	enqueue(queue, "2");
	printf("first: %s last: %s\n", queue->first->message, queue->last->message);
	dequeue(queue);
	printf("first: %s last: %s\n", queue->first->message, queue->last->message);
	enqueue(queue, "hello");
	dequeue(queue);
	printf("is empty? %d\n", isEmpty(queue));
	printf("peek %s\n", peek(queue));

	return (0);
}



// Function used for the test
// Don't go further :)

