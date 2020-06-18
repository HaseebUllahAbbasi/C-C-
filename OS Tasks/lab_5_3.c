#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> 
void *thread_2_method(void *arg)
{

	for (int i = 1; i <= 100; ++i)
	{
		if(i%2==0)
		{
			printf("%d\n",i);
			sleep(1);
		}	
	}
}
void *thread_1_method(void *arg)
{
	for (int i = 1; i <= 100; ++i)
	{
		if(i%2==1)
		{
			printf("%d\n",i);
			sleep(1);
		}	
	}
} 



int main()
{
	pthread_t thread_1,thread_2;
	printf("Before Thread creation 1 \n");
	pthread_create(&thread_1, NULL, thread_1_method, NULL); 	//create thread first parameter thread identification, then thread behaviour, then function that
	//execute in thead and in last parameter to function
	
	
	pthread_create(&thread_2, NULL, thread_2_method, NULL); 	//create thread first parameter thread identification, then thread behaviour, then function that
	//execute in thead and in last parameter to function
	pthread_join(thread_2, NULL); //wait for thread
	
	printf("After Thread 2 completion\n");
	
}
