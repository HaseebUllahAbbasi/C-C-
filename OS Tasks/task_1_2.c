#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *thread_function(void *arg);
char message[] = "Hello World";
int main() 
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start)(void *), void *arg);
	/*
	thread 
	Is the location where the ID of the newly created thread should be stored, or NULL if the thread ID is not required.

	attr 
	Is the thread attribute object specifying the attributes for the thread that is being created. If attr is NULL, the thread is created with default attributes.

	start 
	Is the main function for the thread; the thread begins executing user code at this address.Is the location where the ID of the newly created thread should be stored, or NULL if the thread ID is not required.

	attr 
	Is the thread attribute object specifying the attributes for the thread that is being created. If attr is NULL, the thread is created with default attributes.

	start 
	Is the main function for the thread; the thread begins executing user code at this address.

	arg 
	Is the argument passed to start.



	arg 
	Is the argument passed to start.


	*/
	if (res != 0) 
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);//waiting for thread name mentioned in first parameter,
//second parameter will receive the return value from the thread.
	if (res != 0) 
	{	
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %s\n", (char *)thread_result);
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);
}
void *thread_function(void *arg) 
{
	printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(3);
	strcpy(message, "Bye!");
	pthread_exit("Thank you for the CPU time");
}
