
#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank));
	tank->stacks = malloc(sizeof(struct s_stack));
	tank->stacks[0] = malloc(sizeof(struct s_stack));
	tank->stacks[0]->elem = NULL;
	tank->stacks[0]->sum = 0;
	tank->n = 1;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{

	if (energy < 10 || energy > 100)
	{
		printf("NOT VALID! VALID BAR IS FROM %d TO %d UNITS\n", 10, 100);
		return ;
	}
	if (tank->stacks[tank->n - 1]->sum + energy >= 1001)
	{
		tank->n += 1;
		tank->stacks = realloc(tank->stacks, tank->n);
		tank->stacks[tank->n - 1] = malloc(sizeof(struct s_stack));
	}
	tank->stacks[tank->n - 1]->sum += energy;

	struct s_elem *new_head = malloc(sizeof(struct s_elem));
	new_head->energy = energy;
	new_head->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = new_head;

	printTank(tank);
}

int tankPop(struct s_tank *tank)
{

	if (tank->n == 1 && tank->stacks[tank->n - 1]->sum == 0)
	{
		printf("NO ENERGY\n");
		return(0);
	}

	struct s_elem *temp = tank->stacks[tank->n - 1]->elem;
	int top = temp->energy;
	tank->stacks[tank->n - 1]->sum -= top;
	if (tank->stacks[tank->n - 1]->sum == 0 && tank->n > 1)
	{	
		free(tank->stacks[tank->n - 1]);
		tank->stacks[tank->n - 1] = NULL;
		tank->n -= 1;
	}
	tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;
	printTank(tank);

	free(temp);
	temp = NULL;

	return (top);
}

void printTank(struct s_tank *tank)
{
	if (!tank)
	{
		printf("NO TANKS\n");
		return ;
	}
	
	char *header = "------";
	char *footer = "|    |";
	
	printf("\nnormal");
	for (int i = 1; i < tank->n; i++)
	{
		printf("\tnitro%d", i);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("%s\t", header);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("|%-4d|\t", tank->stacks[j]->sum);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("%s\t", footer);
	}
	printf("\n\n");
}	
