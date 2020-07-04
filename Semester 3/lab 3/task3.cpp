#include<iostream>
using namespace std;
class Link
{
    public:
    string name;
    int age,year_joining;
    Link* next;
};
class List
{
    Link* head;
    public:
    List()
    {
        head = NULL;
    }
    void put_data(Link* obj,string name, int age, int year_joining)
    {
            obj->name = name;
            obj->age = age;
            obj->year_joining = year_joining;

    }
    void insert(string name, int age, int year_joining)
    {
        if(head==NULL)
        {
            Link* new_Node = new Link;
            put_data(new_Node,name,age,year_joining);
            new_Node->next = head;
            head = new_Node;
        }
        else
        {
            Link* current_Node =head;
            while(current_Node->next)
            {
                current_Node = current_Node->next;
            }
            Link* new_Node = new Link;
            put_data(new_Node,name,age,year_joining);
            new_Node->next = current_Node->next;
            current_Node->next = new_Node;
        }


    }
    void display_data(Link* obj)
    {
        cout<<"name : "<<obj->name<<endl;
        cout<<"age : "<<obj->age<<endl;
        cout<<"year of joining : "<<obj->year_joining<<endl;
        cout<<endl;
    }
    void display_head()
    {
        Link* current_Node = head;
        display_data(current_Node);
    }
    void display_all()
    {
        Link* current_Node = head;
        while(current_Node)
        {
            display_data(current_Node);
            current_Node = current_Node->next;
        }
    }
    void search_by_age(int age)
    {
        Link* current_Node = head;
        while(current_Node)
        {
            if(current_Node->age==age)
            {
                display_data(current_Node);
            }
            current_Node = current_Node->next;
        }
        if(current_Node==NULL)
        {
            cout<<"bot found"<<endl;
        }
    }
    void search_by_name(string name)
    {
        Link* current_Node = head;
        while(current_Node&&current_Node->name!=name)
        {
            current_Node = current_Node->next;
        }
        if(current_Node)
        {
            display_data(current_Node);
        }
        else
        {
            cout<<"bot found"<<endl;
        }
    }
    int emp_old()
    {
        int age = -1;
        Link* current_Node = head;
        while(current_Node)
        {
            if(current_Node->age>age)
            {
                age = current_Node->age;
            }
            current_Node = current_Node->next;
        }
        return age;
    }
    void terminate_employee()
    {
        Link* current_Node = head;
        int age = emp_old();
        Link* prev = NULL;

        while(current_Node&&current_Node->age!=age)
        {
            prev = current_Node;
            current_Node = current_Node->next;
        }
        if(current_Node)
        {
            if(prev)
            {
                prev->next = current_Node->next;
                delete current_Node;
            }
            else
            {
                head = current_Node->next;
                delete current_Node;
            }
        }


    }
    void terminate_employee_multi()
    {
        Link* current_Node = head;
        int age = emp_old();
        Link* prev = NULL;
        int repeated_age = 0;
        int deleted = 0;
        while(current_Node)
        {
            if(current_Node->age==age)
            {
                repeated_age++;
            }
            current_Node = current_Node->next;
        }

        do
        {
            current_Node = head;
            while(current_Node&&current_Node->age!=age)
            {
                prev = current_Node;
                current_Node = current_Node->next;
            }
            if(current_Node)
            {
                if(prev)
                {
                    prev->next = current_Node->next;
                    delete current_Node;
                }
                else
                {
                    head = current_Node->next;
                    delete current_Node;
                }
            }
            deleted++;
        }while(deleted<repeated_age);
    }
};
int main()
{
    List obj;
    obj.insert("string",105,1999);
    obj.insert("double",105,1999);
    //obj.display_head();
    obj.insert("int",70,1999);
    obj.insert("byte",90,1998);
    obj.insert("class",90,1999);
    obj.insert(".",20,1999);
    //obj.search_by_name("string");
    //obj.search_by_age(70);
    obj.terminate_employee_multi();//emp_old();//terminate_employee();
    obj.display_all();

}
