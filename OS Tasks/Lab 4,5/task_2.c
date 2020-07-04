#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{

	int p1=fork(); //call fork();
	if(p1==0)
	{
		int p2=fork(); //call fork();
		if(p2==0)
		{
			int p3=fork(); //call fork();
			if(p3==0)
			{
				int p4=fork(); //call fork();
				if(p4==0)
				{
					printf("process 5 %d\n",getpid());

				}
				else
				{
					wait(0);
					printf("process 4 %d\n",getpid());
				}

			}
			else
			{
				wait(0);
				printf("process 3 %d\n",getpid());
				
			}

		}
		else
		{
			wait(0);
			printf("process 2 %d\n",getpid());
			
		}

	}
	else
	{
		wait(0);
		printf("process 1 %d\n",getpid());
	}
	
}
