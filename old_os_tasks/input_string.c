#include <stdio.h>
#include <stdlib.h>

int main()
{
	char full_name[50];
	int age;
	FILE *fptr;
	fptr = fopen("file2.txt","w");

	if(fptr==NULL)
	{
		printf("Error\n");
	}
	printf("Enter the number and then age \n");
	scanf("%s %d",full_name,&age);

	fprintf(fptr,"%s %d",full_name,age);
	fclose(fptr);
}