#include "header.h"
#include <string.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{

  struct s_art **artA = (struct s_art **)a;
  struct s_art **artB = (struct s_art **)b;

  return ( strcmp((*artA)->name, (*artB)->name));
}
void sortArts(struct s_art **arts)
 {
 	int i = 0;
 	while (arts[i] != '\0')
 		i++;
 	qsort(arts, i, sizeof(*arts), (int(*)(const void *, const void *))compare);
 	return;
}