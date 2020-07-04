#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> 
void *thread_1_method(void *arg)
{
	sleep(2);
	printf("Method of thread 1 is called \n");
	return NULL;
}
void *thread_2_method(void *arg)
{
	sleep(4);
	printf("Method of thread 2 is called \n");
	return NULL;
} 



int main()
{
	pthread_t thread_1,thread_2;
	printf("Before Thread creation 1 \n");
	pthread_create(&thread_1, NULL, thread_1_method, NULL); 	//create thread first parameter thread identification, then thread behaviour, then function that
	//execute in thead and in last parameter to function
	pthread_join(thread_1, NULL); //wait for thread
	
	printf("the Thread 1 is completed\n");
	
	printf("Before Thread creation  2 \n");
	
	pthread_create(&thread_2, NULL, thread_2_method, NULL); 	//create thread first parameter thread identification, then thread behaviour, then function that
	//execute in thead and in last parameter to function
	pthread_join(thread_2, NULL); //wait for thread
	
	printf("After Thread 2 completion\n");
	
}
