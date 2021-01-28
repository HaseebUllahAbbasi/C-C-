#include <stdio.h>
int main()
{
    printf("\t\t------------------------------------------------------------------------\n");
    printf("\n\n\t\t\t\t\tASCII TABLE \n\n");

    printf("\t\t------------------------------------------------------------------------\n");
    printf("\n\n");
    for(int i=0; i<255; i++)
    {
        printf("\t\tDecimal : %d  ||  Hexadecimal :%x  ||  Octal :%o  ||  Binary : ",i,i,i);
        bin(i);
        printf("\n");
    }

}
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");

}
