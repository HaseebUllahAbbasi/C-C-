#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	FILE *fptr;
	fptr = fopen("file1.txt","w");

	if(fptr==NULL)
	{
		printf("Error\n");
	}
	printf("Enter the number\n");
	scanf("%d",&num);

	fprintf(fptr, "%d",num);
	fclose(fptr);
}