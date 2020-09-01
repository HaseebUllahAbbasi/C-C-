#include<iostream>
#include "stdlib.h"
using namespace std;
int main()
{
  string message = "please enter the sda number to remove permissions";
  string number_sda = "";
  bool run = true;
  while(run)
  {
    cout<<message<<endl;
    cout<<"write 0 for exit"<<endl;
    string commond_1 = "sudo fsck -f /dev/sda";
    string commond_2 = "sudo ntfsfix /dev/sda";
    cin>>number_sda;
    if(number_sda=="0")
      break;
    commond_1+=number_sda;
    commond_2+=number_sda;

    char cmd_1[commond_1.length()];
    char cmd_2[commond_2.length()];
    for(int i=0; i<=commond_1.length(); i++)
    {
      cmd_1[i] = commond_1[i];
    }
    for(int i=0; i<=commond_2.length(); i++)
    {
      cmd_2[i] = commond_2[i];
    }


    system (cmd_1);
    system (cmd_2);
  }
}
