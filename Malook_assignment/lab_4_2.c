#include <stdio.h>
int main()
{
    float num;
    double sum = 0.0 ;
    do
    {
        printf("Enter the non zero number : ");
        scanf("%f",&num);
        sum+=num;
    }while(num!=0.0);
    printf("\n\nthe total sum is : %f",sum);
}
