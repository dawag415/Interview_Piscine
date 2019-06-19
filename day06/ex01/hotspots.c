#include "header.h"
int selectHotspots(struct s_hotspot **hotspots)
{
	int i=0;
	int j=0;
	int count=0;
	int range=0;
	int flag;
	int jrange;
	if (!hotspots)
		return 0;
	while (hotspots[i])
	{
		range=hotspots[i]->pos + hotspots[i]->radius;
		flag=0;
		j=0;
		while(hotspots[j])
		{
			jrange=hotspots[j]->pos - hotspots[j]->radius;
			if (range < jrange)
			{	flag =1;
				break;
			}
			j++;
		}
		if (flag ==0)
			count++;
		i++;
	}
	return (count);
}
