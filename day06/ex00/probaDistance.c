#include "header.h"
#include <stdlib.h>
double probaDistance(int dist, int *locations, int n)
{	int i=0;
	int j=0;
	int k=0;
	double count =0.0f;
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n ; j++)
		{
			k++;
			if (abs(locations[j]-locations[i]) > dist)
				count++;
		}
	}
	return (count/(k));

}