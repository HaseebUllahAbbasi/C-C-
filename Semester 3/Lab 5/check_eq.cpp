#include <iostream>
using namespace std;
struct Balance
{
	int maxSize,stackTop;
	char *Array;
	Balance(string str)
	{
		maxSize = str.length();
		stackTop=0;
		Array=new char[maxSize];
	 }
	void push(char str)
	{
	 	Array[stackTop++] = str;
	}
	void pop()
	{
		stackTop--;
	}
	bool is_balance()
	{
		return(stackTop==0);
	}
};
int main()
{
	string str;
	getline(cin,str);
	Balance obj(str);
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			obj.push(str[i]);
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			obj.pop();
		}
	}
	cout<<obj.is_balance();
}
