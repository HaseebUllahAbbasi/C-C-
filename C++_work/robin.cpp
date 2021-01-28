#include<iostream>
using namespace std;
int fun(int n)
{
    if(n==1) return 0;
    else if(n==2) return 1;
    else return n-1 + fun(n-1);
}
int main()
{
   cout<< fun(20);
}
