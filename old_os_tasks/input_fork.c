#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("before fork\n");
	char text[50];
	scanf("%[^\n]%*c",text);
	printf("the message is  %s",text);
	int temp = getpid();
	int  n = fork();
	printf("the message is  %s",text);

	printf("after fork and the process is %d  and the chidld process is %d\n",temp,n);


}