#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> 
void *thread_1(void *arg)
{
	sleep(1);
	printf("Method of thread 1 is called \n");
	return NULL;
} 
int main()
{
	pthread_t thread_id;
	printf("Before Thread creation \n");
	pthread_create(&thread_id, NULL, thread_1, NULL); 	//create thread first parameter thread identification, then thread behaviour, then function that
	//execute in thead and in last parameter to function
	pthread_join(thread_id, NULL); //wait for thread
	printf("After Thread completion\n");
	
}