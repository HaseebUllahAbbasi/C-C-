#include<iostream>
using namespace std;
int main()
{

    char *pointer; //= "Wah wah";
    cin>>pointer;
    int i=0;
    while(pointer[i])
    {
        cout<<pointer[i++]<<" ";
    }
    cout<<"i is "<<i<<endl;
    char array[i];
    for(int z=0; z<i; z++)
    {
        array[z] = pointer[z];
    }
    cout<<"copied"<<endl;
    for(int z=0; z<i; z++)
    {
        cout<<array[z];
    }
    cout<<"finished"<<endl;
}
