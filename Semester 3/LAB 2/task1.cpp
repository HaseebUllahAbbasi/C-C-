/*
Task 1. Create a dynamic array of integer type and with the size of 3. Prompt the user to enter a number and after entering each number, ask user to enter Y to continue and any other key to exit. If the number of integer entered exceeds the size of array, create another dynamic array of doubled size, copy the content of previous array into new array, delete the previous array and keep getting data for the new one. 
For example, initially the size of dynamic array will be 3, however, if user enters 4th number, you cant store it in array. In that case, create another array with size of 6, copy the three numbers stored in first array, delete the first array and keep getting data from user. In case if user enters 7th number, create another array of size 12 and continue the process.
*/
#include<iostream>
using namespace std;
main()
{
	int size=3, *ptr2,i=0;
	int *ptr = new int[size];
	char ch;
	do
	{
		cout<<"Enter value ";
		cin>>ptr[i++];
		if(i==size)
		{
			size*=2;
			ptr2= new int[size];
			for(int l=0 ; l<=size/2; l++)
			{
				ptr2[l]=ptr[l];
			}
			delete []ptr;
			ptr=ptr2;
				
		}
		cout<<"Press y to continue or else to exit";
		cin>>ch;
		cin.ignore();
		
	}while(ch=='y');
	
	for(int k = 0 ; k<i ; k++)
	{
		cout<<"Entered num is "<<k+1<<" "<<*(ptr+k)<<endl;
	}
}			
