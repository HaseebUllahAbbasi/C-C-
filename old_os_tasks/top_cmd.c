#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	/* fork a child process */
	pid = fork ();
	printf("in execution");
	if (pid < 0)
	 { /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) 
	{ /* child process */
		printf("child is started\n");
		execlp ("/bin/ls","ls -l",NULL);
		

	}
	else
	{ /* parent process */
	/* parent will wait for the child to complete */
		printf("process is running parent\n");
		printf("Child Complete         ");
	}
}
