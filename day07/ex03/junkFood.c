

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
  struct s_queue *q = queueInit();
  struct s_queue *f = queueInit();
  struct s_node *loc = NULL;
  struct s_node *curr = NULL;
  struct s_sellers *sell = (struct s_sellers*)malloc(sizeof(struct s_sellers));
  int found = 0;
  int depth = 0;
  int i = -1;

  while (parisPlaces->places[++i])
    if (!strcmp(parisPlaces->places[i]->name, youAreHere))
    {
      loc = parisPlaces->places[i];
      break;
    }
  if (!loc) return NULL;
  if (loc->hasCerealBar)
  {
    sell->distance = 0;
    sell->placeNames[0] = loc->name;
    return (sell);
  }
  enqueue(q, loc);
  loc->visited = 1;
  enqueue(q, NULL);
  int j = -1;

  while (!found && q->first->place)
  {
    while ((curr = dequeue(q)))
    {
      curr->visited = 1;
      if (curr->hasCerealBar) enqueue(f, curr), found += 1;
      else if (!found)
        for (j = 0; curr->connectedPlaces[j]; j++)
          if (!curr->connectedPlaces[j]->visited)
          {
            curr->connectedPlaces[j]->visited = 1;
            enqueue(q, curr->connectedPlaces[j]);
          }
    }
    if (!found)
      depth += 1, enqueue(q, NULL);
  }
  if (!found) return (NULL);
  else
  {
    sell->distance = depth;
    sell->placeNames = (char**)malloc((found+1) * sizeof(char*));
    for (int z = 0; z < found; z++)
      sell->placeNames[z] = dequeue(f)->name;
  }
  sell->placeNames[found]=NULL;
  return (sell);
}