#include<iostream>
using namespace std;
class Link
{
    public:
    int data;
    Link *next, *prev;
};
class List
{
    Link* head, *tail;
    int count;
    public:
    List()
    {
         head = NULL;
         tail =NULL;
         count = 0;
    }
    insert(int x)
    {
        Link* new_Node = new Link;
        new_Node->data = x;
        if(head==NULL)
        {
            new_Node->next = head;
            new_Node->prev = tail;
            tail = new_Node;
            head = new_Node;
        }
        else
        {
            new_Node->prev = tail;
            new_Node->next = tail->next;
            tail->next = new_Node;
            tail = new_Node;
        }
        count++;
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
        cout<<"completed the display_List_backward"<<endl;
    }
    void delete_head()
    {

        Link* current = head;
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
            count--;
        }
        else if(head->next==NULL)
        {
            head = current->next;
            head->prev = NULL;
            delete current;
            count--;
        }
        else if(head->next)
        {
            head = current->next;
            head->prev = NULL;
            delete current;
            count--;
        }
    }
};
int main()
{
    List obj;
    obj.insert(1);
    obj.insert(5);
    obj.display_List_forward();
    obj.display_List_backward();
    obj.delete_head();
}
