#include<iostream>
using namespace std;
//unordered with count
class Link
{
    public:
    int data;
    Link *next, *prev;
};
class List
{
    Link* head;
    Link* tail;
    int count;
    public:
    List()
    {
        count = 0;
        head = NULL;
        tail = NULL;
    }
    void insert(int x)
    {
        count++;
        Link* new_Node = new Link;

        if(head==NULL)
        {
            new_Node->data = x;
            head = new_Node ;
            tail = new_Node ;
            head->next = NULL;
            tail->prev = NULL;
        }
        else if(head->data>x)
        {
            new_Node->data = x;
            head->prev = new_Node;
            new_Node->next = head;
            head = new_Node;
        }
        else if(tail->data<x)
        {
            new_Node->data = x;
            new_Node->prev = tail;
            new_Node->next = NULL;
            tail->next = new_Node;
            tail = new_Node;
        }
        else
        {
            Link* t_current = NULL;
            Link* current_Node = head;
            while(current_Node->data<=x&&current_Node)
            {
                t_current = current_Node;
                current_Node = current_Node->next;
            }
            new_Node->data = x;
            new_Node->next = current_Node;
            current_Node->prev = new_Node;
            new_Node->prev = t_current;
            t_current->next = new_Node;
        }
    }
    void display_head()
    {
        cout<<head->data<<endl;
    }
    void display_List_forward()
    {
        Link* current_Node = head;
        while(current_Node)
        {
            cout<<current_Node->data<<"\t";
            current_Node = current_Node->next;
        }
        cout<<"completed the display_List_forward"<<endl;

    }
    void display_List_backward()
    {
        Link* current_Node = tail;
        while(current_Node)
        {
            cout<<current_Node->data<<"\t";
            current_Node = current_Node->prev;
        }
        cout<<"completed the display_List_forward"<<endl;
    }
    void delete_Node(int x)
    {
        if(head->data==x)
        {
            Link* current = head;
            head = head->next;
            head->prev = NULL;
            count--;
        }
        else if(tail->data==x)
        {
            Link* current = tail;
            tail = tail->prev;
            tail->next = NULL;
            count--;

        }
        else
        {
            Link* current_Node = head;
            Link* t_currnet = NULL;
            while(current_Node&&current_Node->data!=x)
            {
                t_currnet =  current_Node;
                current_Node  = current_Node->next;
            }
            if(current_Node)
            {
                t_currnet->next = current_Node->next;
                current_Node->next->prev = t_currnet;
                delete current_Node;
                count--;
            }
            else
            {
                cout<<"not found"<<endl;
            }
        }
    }


};
int main()
{
    List obj;
    obj.insert(9);
    obj.insert(12);
    obj.insert(8);
    obj.insert(7);
    obj.insert(90);
    obj.insert(89);
    obj.delete_Node(7);
    obj.delete_Node(90);
    obj.delete_Node(12);
    obj.display_List_backward();

    obj.display_List_forward();

}
