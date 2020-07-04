/*
    2. Suppose that we have the following message stored in char array named message as below
	char message[12] = "Hello world";
Encrypt and display the given message using encryption keys of 
    a. 0
    b. 2
    c. -3
    d. 20

*/
#include<iostream>
using namespace std;
int main()
{
	char message[12] = "Hello world";
	int key;
	cout<<"Enter key = ";
	cin>>key;
	for(int i=0 ; i<12 ; i++)
	{
		cout<<char(message[i]+key);
	}
	
}
