
#include <stdio.h>
int main()
{
    int input;
    do
    {
        printf("please enter the positive number:");
        scanf("%d",&input);
    }while(input<0);

    for(int i=1; i<=input; i++)
    {
        if(i%5==0)
            printf("%d ",i);
    }
}
