#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int p = fork(); //call fork();
    printf("this is the p value : %d\n", p);

    if (p == 0)
    {
        printf("\n Hi I am child process with id %d\n", getpid());
    }
    else
        printf("\nHi I am Parent Process with id %d\n", getpid());
}