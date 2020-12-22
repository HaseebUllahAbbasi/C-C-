#include<iostream>
using namespace std;
class Link
{
	public:
	int data;
	Link* next;
};
class List
{
	Link *head;
	int count;
	public:
	List()
	{
		head = NULL;
		count = 0;
	}
	void insert(int x,int ind)
	{
		if(ind<0)
		{
			cout<<"ind is less than 0"<<endl;
			return;
		}
		if(ind==0)
		{
			Link *new_Node = new Link;
			new_Node->next = head;
			new_Node->data = x;
			head = new_Node;
			count++;
			return;
		}
		if(ind>0)
		{
			Link* current = head;
			int number = 1;
			while(current&&number<ind)
			{
				current = current->next;
				number++;
			}
			if(ind>0&&current==NULL)
			{
				cout<<"limit exceeded"<<endl;
				return;
			}
			Link* new_node = new Link;
			new_node->data = x;
			new_node->next = current->next;
			current->next =  new_node;
			count++;
		}
	}
	void display_head()
	{
		Link* node = head;
		cout<<node->data;
	}
	void display_list()
	{
		Link* current = head;
		while(current)
		{
			cout<<current->data<<"\t";
			current = current->next;
		}
	}
	void deletion(int x)
	{
		Link* current = head;
		Link* prev = NULL;
		while(current&&current->data!=x)
		{
			prev = current;
			current = current->next;
		}
		if(current)
		{
			if(prev)
			{
				prev->next = current->next;
				delete current;
				count--;
			}
			else
			{
				head = current->next;
				delete current;
				count--;
			}
		}
	}
	int search(int x)
	{
		int number = 0;
		Link* current = head;
		while(current&&current->data!=x)
		{
			number++;
			current = current->next;
		}
		if(current)
		{
			return number;
		}
		return -1;
	}
	int length()
	{
		return count;
	}
	void merge(List* obj)
	{
		Link* new_list_head = obj->head;

		Link* current = head;
		while(current->next)
		{
			current=current->next;
		}
		current->next = new_list_head;
	}
};
int main()
{
	List obj1;
	obj1.insert(1,0);
	obj1.insert(11,1);
	obj1.insert(111,0);
	obj1.display_list();
	cout<<endl;
	List obj2;
	cout<<"\n";
	obj2.insert(12,0);
	obj2.insert(112,0);
	obj2.insert(1112,1);
	obj2.display_list();

	obj2.merge(&obj1);
    obj2.display_list();
}