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
	char dis_play_top()
	{
	    return Array[stackTop-1];
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
		    //cout<<obj.dis_play_top();
			if((str[i]==')'&&(obj.dis_play_top()=='('))||(str[i]=='}'&&(obj.dis_play_top()=='{'))||(str[i]==']'&&(obj.dis_play_top()=='[')))
            {
                obj.pop();
            }
            else
            {
                cout<<"not balanced";
                return 0;
            }
		}
	}
	cout<<obj.is_balance();
}
