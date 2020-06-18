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
		perror("uname doesn't return 0");
	}
	printf("System name  %s \n",buff.sysname);
	/* code */
	return 0;
}

