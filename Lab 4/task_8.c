#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
int main()
{
    int p = fork(); //call fork();
    if (p == 0)
    {
        printf("\n Hi I am child process with id %d\n", getpid());
        sleep(5); //sleep for 5 seconds
        printf("\n My Parent id is %d\n", getppid());
        exit(0);
    }
    else
    {
        wait(0);
        printf("\nHi I am Parent Processwith id %d\n", getpid());
    }
    printf("\n The End");
    return 0;
}