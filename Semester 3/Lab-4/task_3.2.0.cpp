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
    void display_List_forward()
    {
        int printed = 0;
        Link* current_Node = head;
        while(printed<count)
        {
            printed++;
            cout<<current_Node->data<<"\t";
            current_Node = current_Node->next;
        }
        cout<<"completed the display_List_forward"<<endl;
    }
    void insert(char data)
    {
        if(head==NULL)
        {
            Link* new_Node = new Link;
            new_Node->data = data;
            head = new_Node;
            tail = new_Node;
            head->next = head;
            count++;
        }
        else
        {
            Link* new_Node = new Link;
            new_Node->data = data;
            tail->next = new_Node;
            new_Node->prev = new_Node;
            new_Node->next = head;
            tail  = new_Node;
            count++;
        }
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
        obj.insert(check[i]);
    }
    obj.display_List_forward();


    //obj.display_List_forward();
    //obj.palindrome();
}
