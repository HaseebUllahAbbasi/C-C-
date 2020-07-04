#include<iostream>
using namespace std;
//unordered with count
class Link
{
    public:
    string data;
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
    void insert(string x,int index)
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
    
};
int main()
{
    List obj;
    obj.insert("string",-1);
    obj.insert("string",1);
    obj.insert("string",11);
    
    
    obj.insert("int ",0);
    obj.insert("string",0);
    
    obj.display_List_backward();
    obj.display_List_forward();
    
    
}