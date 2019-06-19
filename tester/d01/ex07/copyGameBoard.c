#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *dupe = malloc(sizeof(struct s_node));
	struct s_node *start = dupe;
	struct s_node *cur = dupe;
	struct s_node *ref = node;

	cur->value = ref->value;
	ref = ref->next;

	while (ref)
	{
		struct s_node *tmp = malloc(sizeof(struct s_node));
		tmp->value = ref->value;
		tmp->random = NULL;

		cur->next = tmp;
		cur = cur->next;
		ref = ref->next;
	}
	cur->next = NULL;
	cur = dupe;
	ref = node;

	while (cur)
	{
		struct s_node *tmp = start;

		if (ref->random == NULL)
			cur->random = NULL;
		else if (ref->random->value == ref->value)
			cur->random = cur;
		else while (tmp && tmp->value != ref->random->value)
		{
			tmp = tmp->next;
		}
		if (ref->random && ref->random->value != ref->value)
			cur->random = tmp;

		cur = cur->next;
		ref = ref->next;
	}

	return (dupe);
}