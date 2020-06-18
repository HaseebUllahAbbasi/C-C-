#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr;
	int num, sum =0;
	num = 8 ;
	printf("we have %d to allocate memory\n", num);
	ptr = (int*)malloc(num*sizeof(int));
	if(ptr==NULL)
	{
		printf("Found error\n");
	}
	else
	{
		printf("memory allocation successfull\n");
	}

	for (int i = 0; i < num; ++i)
	{
		ptr[i] = i+1;
	}
	printf("inserted 8 elements in the block as follows\n");
	for (int i = 0; i < num; ++i)
	{
		printf("%d\n",ptr[i]);
	}


}