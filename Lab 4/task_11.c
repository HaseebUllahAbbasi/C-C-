#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(2);
    }
    if (pid == 0)
    {
        printf("I am the child\n");
        exit(0);
    }
    else if (pid > 0)
    {
        printf("I am the parent, i'll wait\n");
        pid = wait(&status);
        printf("I waited the child: %d\n", pid);
    }

    exit(0);
}