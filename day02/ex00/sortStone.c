#include "header.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


static void swap(struct s_stone **cur)
{
	struct s_stone *tmp = *cur;

	*cur = (*cur)->next;
	tmp->next = (*cur)->next;
	(*cur)->next = tmp;
}
void sortStones(struct s_stone **stone)
{
	struct s_stone **i = NULL;
	struct s_stone *tmp = *stone;
	int size = 1;

	bool swapped;
	while (tmp->next)
	{
		size++;
		tmp= tmp->next;
		
	}
	for (int j=size; j>1; j--)
	{
    	swapped = false;
    	i=stone;
        for (int k= 0; k<j;k++)
        {
        	if((*i)->next && (*i)->size > (*i)->next->size)
        	{
           		swap(i);
           		swapped = true;
        	} 
    		i = &((*i)->next);
    	}
    	if (swapped == false)
        break;
    }
}
