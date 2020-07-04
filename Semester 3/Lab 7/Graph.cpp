#include<iostream>
#include<fstream>
using namespace std;
template <class T>
class Link
{
    public:
    T data;
    Link<T> *next;
};
template <class T>
class List
{
    public:
    Link<T> *head,*tail;
    int size;
    List()
    {
        size = 0;
        head = tail = NULL;
    }
    void insert(int data)
    {
        size++;
        Link<T> *node = new Link<T>;
        node->data = data;
        node->next = NULL;
        if(head)
        {
            tail->next = node;
            tail = node;
        }
        else
        {
            head = tail = node;
        }
    }
	void print()
	{
        //cout<<"in print"<<endl;
		Link<T> *node = head;
		while(node)
		{
			cout<<node->data<<" , ";
			node = node->next;
		}
		cout<<endl;
	}
	void delete_linked_list()
	{
		while(head)
		{
			Link<T> *node = head;
			head = head->next;
			delete node;
		}
		cout<<"deleted all the data "<<endl;
	}
	~List()
	{
 	       delete_linked_list();
	}
};
template <class name,class data_type>
class Structure
{
    public:
    name data;
    List<data_type> obj;
};
template <class name,class data_type>
class Graph
{
    public:
    int index, max_size;
    Structure<name,data_type> *array;
    Graph(int number)
    {
        max_size = number;
        array = new Structure<name,data_type>[max_size];
        index = 0;
    }
	void insert(name data)
	{
        //cout<<"insert the data of "<<data<<endl;
		array[index].data = data;
		data_type n = 1;
		while(n>0)
		{
			cin>>n;
			if(n>0)
			array[index].obj.insert(n);
		}
		index++;
	}
	void print()
	{
		for(int i=0 ; i<index; i++)
		{
            		cout<<array[i].data<<" adj are : "<<endl;
			array[i].obj.print();
		}
		//delete[] array;
	}
	~Graph()
	{
		for(int i=0; i<index; i++)
		{
			array[i].obj.delete_linked_list();
		}
	}
	void is_empty()
	{
		if(index==0)
		{
			cout<<" is empty "<<endl;
		}
		else
		{
			cout<<" not empty "<<endl;
		}
	}
	Graph(ifstream &obj)
	{
        int vertex,adj;
	int number;
        obj>>number;
        max_size = number;
        array = new Structure<name,data_type>[max_size];
        index = 0;
        for(int i=0; i<max_size; i++)
        {
            obj>>vertex;
            array[i].data = vertex;
            obj>>adj;
            while(adj>0)
            {
    //            cout<<adj<<endl;
            	array[i].obj.insert(adj);
            	obj>>adj;
            }
            index++;
        }
	}
};
int main()
{
	Graph<string,int> obj(3);
	obj.insert("Sukkur");
	//ifstream dataFile;
	//dataFile.open("file.txt");

	//Graph<int> obj(dataFile);
	//obj.insert(3);
	//obj.insert(1);
	//obj.print();
    obj.print();

}
