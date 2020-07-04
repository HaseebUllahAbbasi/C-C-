#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    fork();
    printf("%d\n",getpid());
    fork();
    printf("%d\n",getpid());
    fork();
    printf("%d\n",getpid());
    
    exit(1);
    
}
