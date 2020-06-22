#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int p = fork(); //call fork();
    if (p == 0)
    {
        printf("\n Hi I am child process with id %d\n", getpid());
        printf("\n My Parent id is %d\n", getppid());
    }
    else
    {
        printf("\nHi I am Parent Process with id %d\n", getpid());
        wait(0); //parent wait until child process completed
        
    }
    return 0;
}