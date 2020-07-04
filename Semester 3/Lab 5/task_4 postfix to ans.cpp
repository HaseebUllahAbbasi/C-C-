#include <iostream>
using namespace std;
class Link
{
public:
    char data;
    Link* next;
};
class Stack
{
    Link* head, *tail;
    int current_size;
    public:
	Stack()
	{
        head = tail = NULL;
	    current_size = 0;
	}
	void push(char data)
	{
            Link* new_Node = new Link;
           new_Node->data = data;
           new_Node->next = NULL;
           if(head==NULL)
           {
               head = tail = new_Node;
           }
           else
           {
               new_Node->next = head;
               head = new_Node;
           }
	}
	char pop()
	{
        if(head==NULL)
       {
           cout<<"list is empty"<<endl;
       }
       else
       {
           Link *current = head;
           char var = head->data;
           head = head->next;
           delete current;
           return var;
       }

    }
	char only_show_top_element()
	{

	}
	char get_las_element()
	{
	}
	void display_top()
	{
        cout<<head->data<<endl;
	}
};
int main()
{
	Stack obj;
	string str = "482/+";//*34*+1+9";
	for(int i=0; i<str.length(); i++)
	{
	    if(str[i]>=48&&str[i]<=57)
        {
            //cout<<str[i]<<" ";
            obj.push(str[i]);
        }
        if(str[i]=='+'||str[i]=='*'||str[i]=='-'||str[i]=='/')
        {
            int a  = int(obj.pop())-48;
            int b  = int(obj.pop())-48;
            char sum = char((a+b)+48);
            cout<<a+b<<endl;
            obj.push(sum);
            //cout<<sum;
        }
	}
}
