#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	FILE *fptr;
	//fptr = fopen("file1.txt","w");

	if((fptr = fopen("file1.txt","r"))==NULL)
	{
		printf("Error\n");
		exit(1);
	}
	fscanf(fptr,"%d",&num);

	printf("value of number is %d",num);
	fclose(fptr);
	
}