#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Array
{
	char *chArray;
	int maxSize, top=-1;

	Array(int size)
	{
		chArray = new char[size];
		maxSize = size-1;
	}

	bool IsArrayEmpty()
	{
		return top==-1;
	}

	bool IsArrayFull()
	{
		return top==maxSize;
	}

	void push(char ch)
	{
		if(!IsArrayFull())
		{
			top++;
			chArray[top] = ch;
		}
		else
		 cout<<"Cannot Insert a new value b/c the Array is full"<<endl;
	}
	void pop()
	{
		if(!IsArrayEmpty())
			top--;

		else
		 cout<<"Cannot Delete a value b/c the Array is Already empty"<<endl;
	}
	char Top()
	{
		return chArray[top];
	}
	int Count()
	{
		return top+1;
	}
};

int main()
{
    ofstream data_file;
    data_file.open("exp.txt");
	int size;
	string str,  str2;

	cout<<"infix to postfix"<<endl;

	cin>>str;

	size=str.length();
	Array *obj = new Array(size);
    bool check;
	for(int i=0; i<size; i++)
	{
	    check = true;
		if(str[i]>=48 && str[i]<=57)
		{
			str2+=str[i];
		}
		else if(str[i]=='/' || str[i]=='*' || str[i]=='+' || str[i]=='-' || str[i]=='%')
		{
		    str2+=",";
			if(obj->Count()!=0)
			{
				if((obj->Top()=='+'|| obj->Top()=='-') && (str[i]=='*'|| str[i]=='/' || str[i]=='%'))
				{
					obj->push(str[i]);
				}
				else if((str[i]=='/')&&(obj->Top()=='*'))
                		{
                	    		obj->push(str[i]);
               			 }
				else if((str[i]=='*')&&(obj->Top()=='/'))
				{
					str2+=obj->Top();
					obj->pop();
					obj->push(str[i]);
				}
				else
				{
						int runner = obj->Count();
							for(int j=0; j<runner; j++)
							{
								str2+=obj->Top();
								obj->pop();
							}
						obj->push(str[i]);
				}
			}
			else
			{
				obj->push(str[i]);
			}
		}
	}
	int temp = obj->Count();
    	str2+=",";
	for(int i=0; i<temp; i++)
	{
		str2+=obj->Top();
		obj->pop();
	}
	cout<<"Postfix is"<<endl;
	cout<<str2<<endl;
	if(data_file)
    {
        data_file<<str2<<"\n"<<endl;
        cout<<"done"<<endl;
    }
}
