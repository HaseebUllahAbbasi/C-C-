#include<iostream>
using namespace std;
template <class T>
class Que
{
    T *ptr_array;
    int max_size, current_size, rear,front;
public:
    Que()
    {
        max_size = 100;
        current_size = 0;
        rear = max_size-1;
        front = 0;
        ptr_array = new T[max_size];
    }
    Que(int number)
    {
        max_size = number;
        current_size = 0;
        rear = max_size-1;
        front = 0;
        ptr_array = new T[max_size];
    }
    void addQueue(T number)
    {
        if(current_size<max_size)
        {
            rear = (rear+1)%max_size;
            ptr_array[rear] = number;
            current_size++;
        }
        else
        {
            cout<<"list is FULL"<<endl;
        }
    }
    ~Que()
    {
        delete []ptr_array;
        current_size = 0 ;
        max_size =0;
        front =0;
        rear = 0;
    }
    void remove_element()
    {
        if(current_size==0)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            front = (front+1)%max_size;
            current_size--;
        }
    }
    void display_front()
    {

        if(current_size==0)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            cout<<"front is ";
            cout<<ptr_array[front]<<endl;
        }
    }
    void display_rear()
    {
        if(current_size==0)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            cout<<"rear is "<<endl;
            cout<<ptr_array[rear]<<endl;
        }
    }
    void display_Que()
    {
        if(front<rear)
        {
            for(int i=front; i<rear+1; i++)
            {
                cout<<ptr_array[i]<<" ";
            }
            cout<<"displayed all the data"<<endl;
        }
        else if(rear<front)
        {
         //   cout<<"in else "<<endl;
            for(int i=front; i<max_size; i++)
            {
                cout<<ptr_array[i]<<" ";
            }
            for(int i=0; i<rear+1; i++)
            {
                cout<<ptr_array[i]<<" ";
            }
        }
        else if(front<rear)
        {
            for(int i=front; i<rear; i++)
            {
                cout<<ptr_array[i]<<" ";
            }
            cout<<"displayed all the data"<<endl;
        }
    }
    void is_Empty()
    {
        if(current_size==0)
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
        delete[] ptr_array;
        max_size = 100;
        current_size = 0;
        rear = max_size-1;
        front = 0;
        ptr_array = new T[max_size];
    }
    void delete_Que()
    {
        ~Que();
    }
    Que(Que<int> &obj)
    {
        front = obj.front;
        rear = obj.rear;
        max_size = obj.max_size;
        ptr_array = new T[max_size];

        if(obj.front<obj.rear)
        {
            for(int i=front; i<rear+1; i++)
            {
                ptr_array[i] = obj.ptr_array[i];
            }
            cout<<"displayed all the data"<<endl;
        }
        else if(obj.rear<obj.front)
        {
            for(int i=front; i<max_size; i++)
            {
                ptr_array[i] = obj.ptr_array[i];
            }
            for(int i=0; i<rear+1; i++)
            {
                ptr_array[i] = obj.ptr_array[i];
            }
        }
        else if(obj.front<obj.rear)
        {
            for(int i=front; i<rear; i++)
            {
                ptr_array[i] = obj.ptr_array[i];
            }
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
    Q1.remove_element();
    Q1.display_Que();
    Que<int>Q2(Q1);
    Q1.display_Que();
}
