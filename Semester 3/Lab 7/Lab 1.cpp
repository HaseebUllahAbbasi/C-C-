#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Stack
{
    int size, *array;
    int count_positive,count_nagative;
    public:
    Stack()
    {
        array  = new int [200];
        count_nagative = 199;
        count_positive = 0;
    }
    public:
    void push(int number)
    {
        if(number>=0)
        {
            array[count_positive] = number;
            count_positive++;
        }
        if(number<0)
        {
            array[count_nagative] = number;
            count_nagative--;
        }
    }
    void display_numbers()
    {
        cout<<"positive"<<endl;
        for(int i=0; i<count_positive; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
        cout<<"negative numbers "<<endl;
        for(int i=199; i>count_nagative; i--)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    int num;
    Stack obj;
    srand(time(0));
    for(int i=0; i<10; i++)
    {

        //int randomNum = rand() % 400 + (-200);
        //cout<<i<<"\t"<<randomNum<<endl;
        //obj.push(randomNum);
        cin>>num;
        obj.push(num);
    }
    cout<<"displaying all numebrs "<<endl;
    obj.display_numbers();
}
