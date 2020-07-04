/*
     Create a structure named empInfo that have the following members(fields) variable
string name, email;
int id;
string designation;
The structure should have the following functions as well
Non value returning function named input that input values from user.
Non value returning function named display that displays values of variables.

*/

#include<iostream>
using namespace std;
struct info
{
	string name,email,des;
	int id;
	void input()
	{
		cout<<"Enter name = ";
		cin>>name;
		cout<<"Enter email = ";
		cin>>email;
		cout<<"Enter designation = ";
		cin>>des;
		cout<<"Enter id = ";
		cin>>id;
	}
	void show()
	{
		cout<<endl;
		cout<<"Name  = "<<name<<endl;
		cout<<"email = "<<email<<endl;
		cout<<"Designation = "<<des<<endl;
		cout<<"ID      = "<<id<<endl;
	}
};
int main()
{
	info obj;
	obj.input();
	obj.show();	
}
