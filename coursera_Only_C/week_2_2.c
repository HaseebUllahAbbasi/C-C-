#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main () {
   double answer, number;
  printf(" Please Enter the Value to calculate Sine :  ");
  scanf("%lf", &number);
  
  answer = sin(number);
  
  printf("\n The Sine value of %lf = %f ", number, answer);
  
  return 0; 
}
