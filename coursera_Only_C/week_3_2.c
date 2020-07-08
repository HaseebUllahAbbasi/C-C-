#include <stdio.h>
#include <stdint.h>
#include <math.h>

void print_sin_cos(double step) 
{

    
    

}

int main()
{
    double interval;
    	printf("\nThe Table for sin\n");
	int i;
	for(i = 0; i <30; i++)
	{
		 interval = i/10.0;
		 printf("sin( %lf ) = %lf \n", interval, fabs(sin(interval)));
	}
	
    	printf("\n\nThe Table for cos\n");
	for(i = 0; i <30; i++)
	{
		 interval = i/10.0;
		 printf("cos( %lf ) = %lf \n", interval, fabs(cos(interval)));
	}

}
