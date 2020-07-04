#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
 int radius;
 printf("Enter radius: ");
 scanf("%d", &radius);
printf("volume is : %lf \n\n", (4 /3.0)*radius*radius*radius );
return 0;
}
