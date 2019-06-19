#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t hash(char *input)
{
	unsigned long hash = 4242;
	int c;
	while ((c = *input++))
		hash = ((hash << 8) + hash) + c;
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *res;

	res = malloc(sizeof(struct s_dict));
	res->capacity = capacity;
	res->items = malloc(sizeof(struct s_item *) * (capacity + 1));
	return (res);
}

int dictInsert(struct s_dict *dict, char *key, int value)
{
	int		index;
	struct s_item	*newpair;
	struct s_item	*ptr;

	newpair = malloc(sizeof(struct s_item));
	if (!newpair)
		return (-1);
	newpair->key = strdup(key);
	newpair->value = value;
	index = hash(key) % dict->capacity;
	ptr = dict->items[index];
	newpair->next = ptr;
	dict->items[index] = newpair;
	return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int index;
	struct s_item *ptr;

	index = hash(key) % dict->capacity;
	ptr = dict->items[index];
	while (ptr != NULL)
	{
		if (strcmp(ptr->key, key) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

char *compress( char *book, struct s_dict *dict)
{
return (dictSearch(dict, name)->price);
}