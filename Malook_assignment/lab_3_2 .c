
#include <stdio.h>
int main()
{
    int input, divi;
    printf("please enter the number to get the multiples : ");
    scanf("%d",&divi);
    do
    {
        printf("please enter the positive number:");
        scanf("%d",&input);
    }while(input<0);

    for(int i=1; i<=input; i++)
    {
        if(i%divi==0)
            printf("%d ",i);
    }
}
