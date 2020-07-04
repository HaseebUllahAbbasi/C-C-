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
    void find(string x)
    {
        int index = 0;
        Link* current_Node = head;
        while(current_Node)
        {
            if(current_Node->data==x)
            {
                cout<<x<<" found at "<<index<<" index"<<endl;
                return;
            }
            current_Node =  current_Node->next;
            index++;
        }
        cout<<"not found in the list"<<endl;
    }
    void delete_data(string x)
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
    List obj;
    //obj.insert("string",-1);
    //obj.insert("string",1);
    //obj.insert("string",11);


    //obj.insert("string",1);
      obj.insert("class",0);
    obj.insert("int",0);
    obj.insert("string",1);
    obj.insert("byte",3);
    //obj.find("string");
    //obj.insert("string",0);
   obj.display_List_backward();
   obj.display_List_forward();


   obj.delete_data("string");
   obj.display_List_backward();
   obj.display_List_forward();


}
