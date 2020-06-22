#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
    printf("before forking\n");
    printf("After forking\n");
    return 0;

}