#include <stdio.h>
int main()
{
    float height, weight, BMI;
    printf("please enter the height : ");
    scanf("%f",&height);
    printf("\nplease enter the weight : ");
    scanf("%f",&weight);

    BMI = ((10000*weight)/(height*height));

    printf("\n\n Your BMI is : %f\n\n",BMI);

    if(BMI<18.5)
        printf("Status is Under Weight");
    else if(BMI<24.9)
        printf("Status is Normal Weight");
    else if(BMI<29.9)
        printf("Status is Over Weight");
    else
        printf("Status is Obese");

}
