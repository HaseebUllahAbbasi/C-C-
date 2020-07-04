#include<iostream>
using namespace std;
template <class T>
class Link
{
    public:
    T data;
    Link<T> *next;
};
template <class T>
class Que
{
    Link<T> *head,*tail;
    int max_size, current_size;
public:
    Que()
    {
        max_size = 100;
        current_size = 0;
        head = tail = NULL;

    }
    Que(int number)
    {
        max_size = number;
        current_size = 0;
        head = tail = NULL;

    }
    void addQueue(T data)
    {
        if(current_size<max_size)
        {
            Link<T> *new_node = new Link<T>;
            new_node->next = NULL;
            new_node->data = data;
            if(head==NULL)
            {
                cout<<"head added"<<endl;
                head = tail = new_node;
                current_size++;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
                tail->next = NULL;
                current_size++;
            }
        }


    }
    ~Que()
    {
        Link<T> *current = head;
        while(current)
        {
            head = head->next;
            delete current;
            current = head;
        }
        head = tail = NULL;
        max_size = 0;
        current_size = 0;
    }
    void remove_element()
    {
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {

        }
    }
    void display_front()
    {

        if(head)
        {
            cout<<head->data<<endl;
        }
        else
        {
            cout<<"is empty"<<endl;
        }
    }
    void display_rear()
    {
        if(tail)
        {
            cout<<tail->data<<endl;
        }
        else
        {
            cout<<"list is null"<<endl;
        }
    }
    void display_Que()
    {
        Link<T> *current = head;
        while(current)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<"displayed all the data"<<endl;
    }
    void is_Empty()
    {
        if(head==NULL)
        {
            cout<<" is empty"<<endl;
        }
        else
        {
            cout<<"not empty"<<endl;
        }
    }
    void is_Full()
    {
        if(current_size==max_size)
        {
            cout<<"list is FULL"<<endl;
        }
        else
        {
            cout<<"array is not full"<<endl;
        }
    }
    void display_size()
    {
        cout<<current_size<<endl;
    }
    void initializeQueue()
    {
        ~Que();
        max_size = 100;
        current_size = 0;
    }
    void delete_Que()
    {
        ~Que();
    }
    Que(Que<int> &obj)
    {
        tail =  head = NULL;
        max_size = 100;
        current_size = 0;
        Link<T> *current_1 = obj.head;
        while(current_1)
        {
            addQueue(current_1->data);
            current_1 = current_1->next;
        }
    }
};
int main()
{
    Que<int> Q1;
    Q1.addQueue(15);
    Q1.addQueue(25);
    Q1.addQueue(4);
    Q1.addQueue(12);
    Q1.addQueue(123);
    Q1.addQueue(75);
    Q1.addQueue(85);
    Q1.addQueue(55);
    //Q1.display_front();
    //Q1.remove_element();
    Q1.display_Que();
    Que<int> Q2(Q1);
    Q2.display_Que();
}
