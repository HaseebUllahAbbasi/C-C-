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
	int max;
	public:
	List()
	{
		head = NULL;
		count = 0;
	}
	int check_max(int num)
	{
	    if(num>max)
            max = num;
	}
	void insert_at_begin(int x)
	{
	    count++;
	    Link *new_Node = new Link;
	    new_Node->data = x;
	    if(head==NULL)
        {
			head = new_Node;

        }
        else
        {
            new_Node->next = head;
            head = new_Node;
        }
        check_max(x);
	}
	void insert_at_end(int x)
	{

        count++;
	    Link *new_Node = new Link;
	    new_Node->data = x;
	    if(head==NULL)
        {
            head = new_Node;
        }
        else
        {
            Link* current = head;
            while(current)
            {
                current = current->next;
            }
            current->next = new_Node;
        }
        check_max(x);
	}
	void insert_after(int index, int data)
	{
	    if(index>count)
	    return;
	    Link* new_Node = new Link;
	    new_Node->data = data;
        Link* current = head;
        int i =0 ;
        while(i<index)
        {
            current = current->next;
            i++;
        }
        new_Node->next = current->next;
        current->next = new_Node;
        count++;
        check_max(data);
	}
	void insert_before(int index, int data)
	{
	    if(index==0)
        {
            cout<<"there will be no insertion before zero";
            return;
        }
	    if(index>count)
        {
            cout<<"you are exceeding index ";
            return;
        }
	    Link *new_Node = new Link;
	    new_Node->data = data;
        Link* current = head;
        int i =0 ;
        while((i+1)<index)
        {
            current = current->next;
            i++;
        }
        new_Node->next = current->next;
        current->next = new_Node;
        count++;
        check_max(data);
	}
	void DeleteN(int x)
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
	void delete_from_begin()
	{
	    if(head==NULL)
            return;
        else
            head = head->next;
	}
	void delete_from_end()
	{
	    if(head==NULL)
            return;
        else
        {
            Link* current = new Link;
            current = head;
            while(current->next->next)
            {
                current = current->next;

            }
            current->next = NULL;
        }
	}
	void Delete()
	{
	    DeleteN(max);
	}
	void delete_list()
	{
	    if(head == NULL)
            return;
        else
        {
            head->next = NULL;
            head = NULL;

        }


	}

};
int main()
{
    }
