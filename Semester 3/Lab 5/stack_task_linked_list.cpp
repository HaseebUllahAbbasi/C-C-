#include<iostream>
#include<string>
using namespace std;
template <class T>
class Link
{
public:
    T data;
    Link<T> *next;
};
template <class T>
class Stack
{
    int current_size, max_size;
    Link<T> *head, *tail;
    public:
    Stack()
	{
	    max_size = 100;
	    head = tail = NULL;
	    current_size = 0;
	}
	Stack(int number)
	{
	    head = tail = NULL;
	    max_size = number;
	    current_size = 0;
	}
	void display_current_size()
	{
        cout<<current_size<<endl;
	}
   void init_stack()
   {
       ~Stack();
       max_size = 100;
       head = tail = NULL;
   }
   bool isEmpty()
   {
       return(current_size==0);
   }
   void push(T data)
   {
       if(current_size<max_size)
       {
           Link<T>* new_Node = new Link<T>;
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
           current_size++;
       }
       else
       {
           cout<<"Can't add to a full stack"<<endl;
       }
   }
   void pop()
   {
       if(head==NULL)
       {
           cout<<"list is empty"<<endl;
       }
       else
       {
           Link<T> *current = head;
           head = head->next;
           delete current;
       }
   }
   void CopyStack(Stack& other_stack)
   {
       cout<<"called"<<endl;
       Link<T> *current= head;
	    while(current)
        {
            head = head->next;
            delete current;
            current = head;
        }
        current_size = 0;
		max_size=other_stack.max_size;
        current_size = other_stack.current_size;
        Link<T> *current_2 = other_stack.head;
        head = NULL;
        Link<T> *current_1 = head;

        while(current_2)
        {
            Link<T> *new_Node = new Link<T>;
            new_Node->data = current_2->data;
            new_Node->next = NULL;
            if(head==NULL)
            {
                head = tail = new_Node;
            }
            else
            {
                tail->next = new_Node;
                tail = new_Node;
            }
            current_2 = current_2->next;
        }

	}
   ~Stack()
	{
	    Link<T> *current= head;
	    while(current)
        {
            head = head->next;
            delete current;
            current = head;
        }
        current_size = 0;

    }
	void display_top()
	{
		if(head)
        {
            cout<<head->data<<endl;
        }
        else
        {
            cout<<"the stack is null"<<endl;
        }
	}
	Stack(Stack<T> &obj)
	{
	    head = tail =  NULL;
	    current_size = 0;
	    max_size = 10;
	    CopyStack(obj);

	}
};
int main()
{
    Stack<int> obj(10);
    obj.push(90);
    obj.push(708);
    Stack<int> obj2(obj);
    obj2.display_top();
}
