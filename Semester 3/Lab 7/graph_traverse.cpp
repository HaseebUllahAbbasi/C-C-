#include <iostream>
#include <list>
using namespace std;
struct Link
{
	int data;
	Link *next;
};
struct List
{
	static int index;
	Link *head,*tail;
	List()
	{
		head=tail=NULL;
	}
	void insert(int data)
	{
		Link* n = new Link;
		n->data  = data;
		n->next = NULL;
		if(head==NULL)
		{
			tail = head = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}
	}
	void display()
	{
		if(!head)
		cout<<"it has no adjacenceis"<<endl;
		Link* n = head;
		while(n)
		{
			cout<<n->data<<" ";
			n = n->next;
		}
		cout<<endl;
	}
	void destroy()
	{
		Link *cur=head;
		while(head)
		{
			cur=head;
			head=head->next;
			delete cur;
		}
	}
	bool empty()
	{
		return head==NULL;
	}
	int vertex()
	{
		if(head)
		return head->data;
		else
		return -1;
	}
};
struct Array
{
	int data;
	List obj;
};
struct graph
{
	int maxSize, gsize, *Boolarray, stackTop, *Stack;
	Array *ar;
	graph(int size)
	{
		maxSize=size;
		gsize=0;
		ar=new Array[size];
		stackTop=0;
	}

	void insert(int val)
	{
		if(!isfull())
		{
			ar[gsize].data=val;
			int num=0;
			cout<<"Enter adjacencies of "<<val<<" Enter negative number to end: "<<endl;
			while(num>=0)
			{
				cin>>num;
				if(num>=0)
				ar[gsize].obj.insert(num);
			}
			gsize++;
		}
	}
	void push(int val)
	{
		Stack[stackTop]=val;
		stackTop++;
	}
	void pop()
	{
		stackTop--;
	}
	void traverse(int n)
	{
		Boolarray = new int[n];
		Stack = new int[n];
		int vertexCount = 0;
		Link *cur;
		bool *Boolarray;
		Boolarray = new bool[n];
		for(int i=0; i<n; i++)
		{
			Boolarray[i]=false;
		}
		int a=0;
		while(vertexCount!=n)
		{
			if(!Boolarray[a])
			{
				Boolarray[a]=true;
				push(ar[a].data);
				cout<<ar[a].data<<endl;
				vertexCount++;
				a=ar[a].obj.vertex();
				if(a==-1)
				{
					pop();
					a=Stack[stackTop-1];
				}
			}
			else
			{
				a=Stack[stackTop-1];
				cur=ar[a].obj.head;
				while(cur && Boolarray[a])
				{
					a=cur->data;
					cur=cur->next;
				}
				if(!cur || !cur->next)
				pop();

				if(stackTop==0 && Boolarray[a])
				{
					a=0;
					while(Boolarray[a])
					{
						a=ar[a].data;
						a++;
					}
				}
			}
		}
	}
	void display()
	{
		if(gsize>0)
		for(int i=0; i<gsize; i++)
		{
			cout<<"Adjacencies of vertex "<<ar[i].data<<endl;
			ar[i].obj.display();
		}
		else
		cout<<"graph is empty"<<endl;
	}
	void destroyGraph()
	{
		for(int i=0; i<gsize; i++)
		{
			ar[i].obj.destroy();
		}
		gsize=0;
	}
	bool isfull()
	{
		return (maxSize==gsize);
	}
};
int main()
{
	cout<<"Enter the maximum size of Graph: "<<endl;
	int size;
	cin>>size;
	graph obj(size);
	cout<<"Enter current size of graph:"<<endl;
	int curSize;
	cin>>curSize;
	int val;
	for(int i=0; i<curSize; i++)
	{
		obj.insert(i);
	}
	obj.traverse(curSize);
}
