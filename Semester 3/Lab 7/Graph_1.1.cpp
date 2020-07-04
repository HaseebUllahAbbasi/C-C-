#include<iostream>
#include<fstream>
using namespace std;
template <class T>
class Link
{
    public:
    T data;
    int distance;
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
    void insert(T data,int distance)
    {
        size++;
        Link<T> *node = new Link<T>;
        node->data = data;
        node->distance = distance;
        node->next = NULL;
        if(head)
        {
            if(head->distance>distance)
            {
                node->next = head;
                head = node;
            }
            else if(tail->distance<distance)
            {
                tail->next = node;
                tail = node;
            }
            else
            {
                Link<T> *current = head;
                Link<T> *T_current = head;
                while(head->distance<distance)
                {
                    T_current = current;
                    current = current->next;
                }
                node->next = current;
                T_current->next = node;
            }
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
			cout<<node->data<<" : ";
			cout<<node->distance<<" , ";
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
    name name_of_city;
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
		array[index].name_of_city = data;
		string name_of_adj_place="1";
		int distance;
		while(name_of_adj_place!="0")
		{

            cout<<"write the name of the adjacent place from "<<data<<endl;
			getline(cin,name_of_adj_place);
            if(name_of_adj_place=="0")
            break;
			cout<<"write the distance between "<<data<<" and "<<name_of_adj_place<<endl;
			cin>>distance;
			if(name_of_adj_place!="0")
			array[index].obj.insert(name_of_adj_place,distance);
		    cin.ignore();

		}
		index++;
	}
	void print()
	{
		for(int i=0 ; i<index; i++)
		{
            		cout<<array[i].name_of_city<<" adj are : "<<endl;
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
};
int main()
{
	Graph<string,string> obj(3);
	obj.insert("Sukkur");
	//ifstream dataFile;
	//dataFile.open("file.txt");

	//Graph<int> obj(dataFile);
	//obj.insert(3);
	//obj.insert(1);
	//obj.print();
	obj.insert("khairpur");
	    obj.print();

}
