
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

float maxTraffic(struct s_graph *parisPlaces, char *eventHere)
{

  struct s_queue *q = queueInit();
  struct s_queue *f = queueInit();
  struct s_queue *n = queueInit();
  struct s_node *loc = NULL;
  struct s_node *curr = NULL;
  int found = 0;

  int i = -1;
  float count=1.0;

  float max;


   while (parisPlaces->places[++i])
    if (!strcmp(parisPlaces->places[i]->name, eventHere))
    {
      loc = parisPlaces->places[i];
      break;
    }
    if (!loc)
      return (-1.0);
 // printf("fuckoff\n");
    // int y=-1;
    // while(loc->connectedPlaces[++y])
       printf("%s\n",loc->name );
  i=-1;

  while (parisPlaces->places[++i])
  { count = 0;
    curr=parisPlaces->places[i];
    enqueue(q, curr);
    enqueue(f, curr);
    curr->visited=1;
    enqueue(q, NULL);
    enqueue(f, NULL);
    enqueue(q,NULL);
    int j = -1;

    while (!found&&q->first->item)
    {
      while ((curr = dequeue(q)))
      { 
        curr->visited = 1;
        int k =-1;
        while (curr->connectedPlaces[++k])
        {  printf("%s\n\n",curr->connectedPlaces[k]->name);
          if (strcmp(curr->connectedPlaces[k]->name, eventHere) == 0)
          {
          found = 1;        
          printf("hello\n");
          enqueue(n,loc);
          count +=1.0;
          }
        }
      }
      enqueue(n,NULL);
 //     printf("fucker\n");
      while ((curr=dequeue(n)))
      {
        printf("noway\n");
        printf("name:%s\n",curr->name);
        printf("locname:%s\n",loc->name);
        printf("curr->population:%d\n",curr->population );
         printf("loc->population:%d\n",curr->population );
         printf("count:%f\n",count  );
        int h=-1;
           while (parisPlaces->places[++h]){
          if (!strcmp(parisPlaces->places[h]->name, curr->name))
     parisPlaces->places[h]->population += ((curr->population)/count);
      }
    }
    }
    if (!found)
      {
        while ((curr=dequeue(f)))
        {
          for (j = 0; curr->connectedPlaces[j]; j++)
            if (!curr->connectedPlaces[j]->visited)
            {
              enqueue(q, curr->connectedPlaces[j]);
            }
        }
        enqueue(q,NULL);
      }
    if (found)
    {
       while (q->first||q->last)
         dequeue(q);
       while (n->first||n->last)
         dequeue(n);
       while (f->first||f->last)
         dequeue(q); 
       found=0;
    }

   int m=-1;
     while (parisPlaces->places[++m])
      parisPlaces->places[m]->visited=0;
  }
  i=-1;
  while(loc->connectedPlaces[++i])
      {
        int h=-1;
       while (parisPlaces->places[++h])
          if (!strcmp(parisPlaces->places[h]->name, loc->connectedPlaces[i]->name))
      if (max < parisPlaces->places[h]->population)
          max = parisPlaces->places[h]->population;
      }
  return (max);
}