/*Print 100 numebr in Sequence */
#include<stdio.h>
#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> 
pthread_t tid[2];
unsigned int i = 0;
pthread_mutex_t mutex;
unsigned int rc;
//prototypes for callback functions

void* even(void*);
void* odd(void*);

int main()
{
    pthread_create(&tid[0],0,&even,0);
    pthread_create(&tid[1],0,&odd,0);
    sleep(3);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}

void* even(void *ptr)
{
     rc = pthread_mutex_lock(&mutex);
     do
     {
         if(i%2 == 0)
         {
             printf("Even:%d\n",i);
             i++;
            sleep(1);

         }
         else
         {
             rc=pthread_mutex_unlock(&mutex);//if number is odd, do not print, release mutex
         }
     } while (i <= 100);
}

void* odd(void* ptr1)
{
    rc = pthread_mutex_lock(&mutex);
    do
    {
        if(i%2 != 0)
        {
            printf("odd:%d\n",i);
            i++;
            sleep(1);
            
        }
        else
        {
            rc = pthread_mutex_unlock(&mutex);//if number is even, do not print, release mutex
        }
    } while (i <= 100);
}
