#include<fstream>
#include<iostream>
//#include<conio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stack>
using namespace std;
int method(string number)
{
    int num = 0;
    int power = 0;
    for(int i=number.length()-1; i>=0; i--)
    {
        num  = num+(((int)(number[i])-48))*pow(10,power);
        power++;
    }
    cout<<num;
    return num;
}
int main()
{
    //method("90");
    stack<int> data;
    ifstream dataFile;
    char temp;
    string exp = "";
    dataFile.open("exp.txt");
    if(dataFile)
    {
        //cout<<"in if"<<endl;
        while(!dataFile.eof())
        {
            exp+=temp;
            //cout<<"in loop"<<endl;
            dataFile>>temp;
        }
    }
    //cout<<exp;
    string number="";
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]>=48&&exp[i]<=57)
        {
            number+=exp[i];
        }
        else if(exp[i]==',')
        {
            int int1 = method(number);
            data.push(int1);
            cout<<int1<<endl;
            number = "";
        }
        else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/')
        {
            int num1 = data.top();
            data.pop();
            int num2 = data.top();
            data.pop();
            switch(exp[i])
            {
                case '+':
                    {
                        int temp = num2+num1;
                        data.push(temp);
                        break;
                    }
                case '-':
                    {
                        int temp = num2-num1;
                        data.push(temp);
                        break;
                    }
                case '*':
                    {
                        int temp = num2*num1;
                        data.push(temp);
                        break;
                    }

                case '/':
                {
                    int temp = num2/num1;
                    data.push(temp);
                    break;
                }
            }
        }
    }
    cout<<"displaying all list"<<endl;
    while(!data.empty())
    {
        cout<<data.top()<<" ";
        data.pop();
    }

}
