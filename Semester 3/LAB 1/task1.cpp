/*
Write a program in C++  to read a list of 10 integer numbers and  arrange  them in such a manner that all the even numbers start from the left and all the odd numbers start from the right.

Example  x ={1,2,3,4,5,6,7,8,9,10)   resultant array =(2,4,6,8,10 ,8,7,5,3,1 }

*/

#include <iostream>
#include <string>
using namespace std;    
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10],c=0;
	for(int i=0 ; i<10 ; i++)
	{
		if(a[i]%2==0)
		{
			b[c++]=a[i];
		}
	}
	for(int k=9 ; k>=0 ; k--)
	{
		if(a[k]%2!=0)
		{
			b[c++]=a[k];
		}
	}
	for(int k=0 ; k<10 ; k++)
	{
		cout<<b[k]<<" ";
	}

       
}

