//program gives sine and cosine table of values
#include<stdio.h>
#include<math.h>
#define PI 3.14159
int start_interval,end_interval,i;     //start interval and end interval in integer type
double rad_val;                       //for radian value   
void sincostab()                      //function for printing table
{
	for(i=start_interval;i<=end_interval;i++)
	{
			printf("Current value: %d\n",i);
			rad_val=i*(PI/(double)180);          //converting value into radians 
			printf("Sine value: %lf    Cosine value: %lf",sin(rad_val),cos(rad_val));        //printing table of sine and cosine values
			printf("\n\n");
	}
}
int main(void)
{
	printf("Enter start value: ");
	scanf("%d",&start_interval);
        printf("Enter end value: ");
	scanf("%d",&end_interval);
	sincostab();                        //call the function
	return 0;
}
