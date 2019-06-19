#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 100);
	tankPush(tank, 100);
	printTank(tank);
tankPop(tank); 
tankPop(tank);
tankPop(tank);
	tankPush(tank, 100);
	tankPush(tank, 100);
	printTank(tank);
	tankPush(tank, 100);
	tankPush(tank, 100);
	printTank(tank);
	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPop(tank);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	
	tankPush(tank, 100);
		printf("%d",tankPop(tank));	printf("%d",tankPop(tank));	printf("%d",tankPop(tank));	printf("%d",tankPop(tank));	printf("%d",tankPop(tank));
	tankPush(tank, 50);
	tankPush(tank, 30);
	printf("%d",tankPop(tank));
	tankPush(tank, 80);
	tankPush(tank, 50);
		tankPush(tank, 10);
	tankPush(tank, 50);
	printTank(tank);

	tankPush(tank, 100);
	tankPush(tank, 50);
	printTank(tank);
	tankPush(tank, 10);
	tankPush(tank, 50);
	printTank(tank);
	tankPush(tank, 100);
	printf("%d",tankPop(tank));
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	tankPush(tank, 100);
	tankPush(tank, 50);	
		printf("%d",tankPop(tank));
			printf("%d",tankPop(tank));
				printf("%d",tankPop(tank));
					printf("%d",tankPop(tank));
						printf("%d",tankPop(tank));
							printf("%d",tankPop(tank));
	tankPush(tank, 100);
	tankPush(tank, 50);
	tankPush(tank, 30);
	printf("%d",tankPop(tank));
	tankPush(tank, 80);
	tankPush(tank, 50);
	

	return (0);
}



// Function used for the test
// Don't go further :)
