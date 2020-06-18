#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

int main()
{
	struct utsname buff;
	errno = 0;
	if(uname(&buff)!=0)
	{
		perror("uname doesnot return 0 so there is error");
		exit(EXIT_FAILURE);
	}
	printf("System name = %s \n",buff.sysname);
	printf("System name = %s \n",buff.sysname);
	
	
}