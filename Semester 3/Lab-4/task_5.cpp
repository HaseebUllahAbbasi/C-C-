#include<iostream>
using namespace std;
class Link
{
	public:
	int data;
	Link* next, *prev;
};
class List
{
	Link* head, *tail;
	int count = 0 ;
	public:
	List()
	{
		head = NULL;
		head = NULL;

	}
	void insert_node(int x)
	{
		if(head==NULL)
		{
			Link* new_Node = new Link;
			new_Node->data = x;
			head = new_Node;
			tail = new_Node;
			tail->next = head;
			head->prev = tail;
		}
		else
		{
			Link* new_Node = new Link;
			new_Node->data = x;
			new_Node->next = head;
			head->prev = new_Node;
			new_Node->prev = tail;
            tail->next = head;
		}
		count++;
	}
	void delete_head()
	{
	    Link* current_Node = head;
        if(head->next==NULL)
        {
            delete current_Node;
            head = NULL;
            tail = NULL;
            cout<<"deleted"<<endl;
        }
        else if(head->next)
        {
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete current_Node;
            cout<<"deleted"<<endl;
        }
        count--;
	}
};
int main()
{
    List obj;
    obj.insert_node(90);

}
