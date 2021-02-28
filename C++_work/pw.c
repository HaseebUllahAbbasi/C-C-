#include<stdio.h>
int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Number = %d",num);

    for(int i=0; i<num; i++)
    {
        printf("in loop");
        for(int j=0; j<num; j++)
        {
            //if( ((i==0 &&  (j==num || j==0 )) )|| (j==0 &&  (i==num || i==0 ) ))
            //{
              //  printf('O');
            //}
             if(i==num || j==num)
            {

                printf('X');
            }
            else
            {
                printf('-');
            }
        }
    }

        printf("in loop");

    return 0;

}
