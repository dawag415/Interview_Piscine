#include "header.h"
#include <string.h>

static int	get_hash(char *string, int size)
{
	int result = 0;
	int power = size - 1;

	for (int i = 0; i < size; i++)
	{
		if (string[i] == 0)
			break ;
		result += string[i] * pow(B, power);
	}
	return (result % M);
}

int howManyJesus(char *bible, char *jesus)
{
	int size = strlen(jesus);
	int count = 0;
	int term = get_hash(jesus, size);

	for (int i = 0; ; i++)
	{
		if (bible[i] == 0)
			break ;
		int cur = get_hash(bible + i, size);
		if (cur == term)
		{
			if ((strncmp(bible + i, jesus, size)) == 0)
				count++;
		}
	}

	return (count);
}