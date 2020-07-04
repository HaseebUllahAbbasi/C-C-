#include<iostream>
#include<string>
using namespace std;
template <class T>
class Stack
{

    public:
    int current_size;
    int top;
    int max_size;
    T *ptr_array;
    Stack()
	{
		max_size=10;
		top=0;
		current_size = 0;
		ptr_array=new T[max_size];
		cout<<max_size<<" Stacks are created successfully "<<endl;
	}
	Stack(int number)
	{
		max_size=number;
		top=0;
		current_size = 0;
		ptr_array=new T[max_size];
		cout<<max_size<<" Stacks are created successfully "<<endl;
	}
   void init_stack()
   {
	   delete []ptr_array;
		max_size=100;
		top=0;
		ptr_array=new T[max_size];
		current_size = 0;
   }
   bool isEmpty()
   {
       return(top==0);
   }
   bool is_Full()
   {
       return(top==max_size);
   }
   void push(T newitem)
   {
       if(current_size<max_size)
       {
           ptr_array[top]=newitem;
           top++;
		   current_size++;
       }
       else
       {
           cout<<"Can't add to a full stack"<<endl;
       }
   }
   void pop()
   {
       if(!isEmpty())
       {
           top--;
           cout<<"last entered item is deleted"<<endl;
       }
       else
        cout<<"Can't remove from an empty stack"<<endl;
   }
   void CopyStack(Stack& other_stack)
   {
		delete []ptr_array;
		max_size=other_stack.max_size;
		top=other_stack.top;
		ptr_array=new int[max_size];

   //copyother stack into this stack
		for(int i=0;i<top;i++)
		{
            ptr_array[i]=other_stack.ptr_array[i];
		}

	}
    void display()
    {
		for(int i=0; i<top;i++)
		{
			cout<<ptr_array[i]<<" ";
		}
		cout<<endl;
    }
   ~Stack()
	{
       delete []ptr_array;
	   top = 0;
	}
	void display_top()
	{
		cout<<ptr_array[top-1]<<endl;
	}
	Stack(Stack<T> &obj)
	{
	    CopyStack(obj);
	}
};
int main()
{
    Stack<int> obj(10);
    obj.push(90);
    obj.push(708);
    Stack<int> obj1(obj);
    obj.display();
}
