#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("before process\n");
	int n =  fork();
	//printf("created a process\n %d",n);
	int n_1 = getpid();
	printf("got a process\n %d",n_1);
	printf("ended \n");
}
