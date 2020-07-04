/*
    5. Repeat task 4 but this time using classes instead of struct. Here are the requirements
        a. name, email, id and designations should be private.
        b. Both member functions should be public as you need some public method to access private member variables.

*/
#include<iostream>
using namespace std;
class info
{
	string name,email,des;
	int id;
	public :
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
