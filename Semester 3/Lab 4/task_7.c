#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    int p = fork(); //call fork();
    if (p == 0)
    {
        printf("\n Hi I am child process with id %d\n", getpid());
        exit(0);
        printf("\n My Parent id is %d\n", getppid());
    }
    else
    {
        printf("\nHi I am Parent Process with id %d\n", getpid());
    }
    return 0;
    
}