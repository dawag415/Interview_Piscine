#include "header.h"
#include <string.h>

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *ref = city;
	struct s_city *ret = city;
	for (int i = 0; i <= n; i++)
	{
		if (ref == NULL)
			return (NULL);
		ref = ref->next;
	}
	while (ref != NULL)
	{
		ret = ret->next;
		ref = ref->next;
	}
	return (ret->name);
}