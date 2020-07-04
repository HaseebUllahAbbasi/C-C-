#include<iostream>
#include<string.h>
using namespace std;

class Link
{
    public:
    char data;
    Link *next,*prev;
};
class List
{

    Link *head, *tail;
    int count;
    public:
    List()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    void insert(char x,int index)
    {
        if(index>count)
        {
            cout<<"you have exceeded the limit of the list"<<endl;
            return;
        }
        else if(index<0)
        {
            cout<<"you have entered a negative index number "<<endl;
            return;
        }
        else if(index==0)
        {
            if(head==NULL)
            {
                Link* new_Node = new Link;
                new_Node->data = x;
                new_Node->next = NULL;
                new_Node->prev = NULL;
                tail = new_Node;
                head = new_Node;
                cout<<"inserted head in empty list"<<endl;
            }
            else
            {
                Link* new_Node = new Link;
                new_Node->data = x;
                new_Node->prev = head->prev;
                new_Node->next = head;
                head->prev = new_Node;
                head = new_Node;
                cout<<"entered the head in non empty List"<<endl;
            }
            count++;
        }
        else if(count>=index)
        {
            Link* current_Node = head;
            int check_counter = 1;
            while(current_Node->next&&check_counter<index)
            {
                current_Node = current_Node->next;
            }

            Link* new_Node = new Link;
            new_Node->data = x;
            if(count==index)
            {
                new_Node->next = current_Node->next;
                new_Node->prev = current_Node;
                current_Node->next = new_Node;
                tail = new_Node;
            }
            else
            {
                new_Node->next = current_Node->next;
                new_Node->prev = current_Node;
                current_Node->next->prev = new_Node;
                current_Node->next = new_Node;
            }
            count++;
        }

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
    void delete_data(char x)
    {

        Link* current_Node = head;
        Link* t_current = NULL;

        if(head->data==x&&head->next==NULL)
        {
            delete current_Node;
            head= NULL;
            tail = NULL;
            cout<<"head deleted"<<endl;
            count--;
            return;

        }
        while(current_Node&&current_Node->data!=x)
        {
                t_current = current_Node;
                current_Node = current_Node->next;
        }
        if(current_Node)
        {
            if(t_current&&current_Node->next)
            {
                t_current->next = current_Node->next;
                current_Node->next->prev = t_current;
                delete current_Node;
            }
            else if(t_current&&current_Node->next==NULL)
            {

                t_current->next = current_Node->next;
                tail = t_current;
            }
            else if(t_current==NULL)
            {
                head = current_Node->next;
                head->prev = current_Node->prev;
                delete current_Node;
            }
            count--;
        }
        else
        {
            cout<<"not found"<<endl;
        }
    }
};
int main()
{
    cout<<"write the number "<<endl;
    string check;
    getline(cin,check);
    //cout<<check.length();
    int length = check.length();
    //char array[length];
    List obj;

    for(int i=0; i<length; i++)
    {
        obj.insert(check[i],i);
    }
    obj.display_List_forward();


    //obj.display_List_forward();
    //obj.palindrome();
}
