#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("before fork\n");
	int temp = getpid();
	int  n = fork();
	printf("after fork and the process is %d  and the chidld process is %d\n",temp,n);


}