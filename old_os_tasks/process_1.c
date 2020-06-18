#include <stdio.h>
#include <unistd.h>

int main()
{
	int proc_id,par_pro_id;
	proc_id = getpid();
	par_pro_id = getppid();
	printf("process id %d\n ," ,proc_id);
	printf("parent process  id %d\n ," ,par_pro_id);
	
	return 0;
}