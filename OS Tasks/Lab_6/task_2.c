#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";
int main()
{
	char inbuf[MSGSIZE];
	int p[2], pid, nbytes;
	if (pipe(p) < 0)
	exit(1);
/* continued */
	if ((pid = fork()) > 0)
	{
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
		printf("done with the writing \n");
		wait(0);
		//if wait is removed then the execution ends safely
	}
	else 
	{
		printf("started printing\n");
		while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)	
			printf("%s \n", inbuf);
			
		printf("Finished reading\n");
			
	}
	return 0;
}