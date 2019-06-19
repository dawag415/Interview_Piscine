#include <limits.h>
#include <stdlib.h>
#include "header.h"

int isEmpty(struct s_deque *q)
{
  return (q->first == NULL);
}

struct s_deque *dequeInit(void)
{
  struct s_deque *d = (struct s_deque*)malloc(sizeof(struct s_deque));
  if (d != NULL)
		d->first = d->last = NULL;
  return (d);
}

void pushFront(struct s_deque *d, int value)
{
  struct s_dequeNode *new = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));

  new->next = d->first;
  new->prev = NULL;
  new->value = value;
  d->first = new;
  if (d->last == NULL)
  {
		d->first = d->last = new;
	}
  else
  {
		d->first->prev = new;
		d->first = new;
	}
}

void pushBack(struct s_deque *d, int value)
{
  struct s_dequeNode *new = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));

  new->value = value;
  new->prev = d->last;
  new->next = NULL;
  if (d->first == NULL)
  {
		d->first = d->last = new;
	}
  else
  {
		d->last->next = new;
		d->last = new;
	}
}

int popFront(struct s_deque *d)
{
  if (!d->first) return (INT_MIN);
  int val = d->first->value;
  struct s_dequeNode *n = d->first;

  if (d->first == d->last)
		d->first = d->last = NULL;
	else
		d->first = n->next;
  free(n);
  return (val);
}

int popBack(struct s_deque *d)
{
  if (!d->last) return (INT_MIN);
  int val = d->last->value;
  struct s_dequeNode *n = d->last;

  if (d->first == d->last)
		d->first = d->last = NULL;
	else
		d->last = n->prev;
  free(n);
  return (val);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
  struct s_deque *deque = dequeInit();
  struct s_max *max = (struct s_max*)malloc(sizeof(struct s_max));
  int i = -1;

  max->max = (int*)malloc(sizeof(int) * (n - (k + 1)));
  while (++i < k)
  {
    while (!isEmpty(deque) && arr[i] >= arr[deque->last->value])
      popBack(deque);
    pushBack(deque, i);
  }
  max->max[i - k] = arr[deque->first->value];
  while (i < n)
  {
    while (!isEmpty(deque) && arr[i] >= arr[deque->last->value])
      popBack(deque);
    while (!isEmpty(deque) && deque->first->value <= i - k)
      popFront(deque);
    pushBack(deque, i);
    i++;
    max->max[i - k] = arr[deque->first->value];
  }
  max->length = i - k + 1;
  return (max);
}