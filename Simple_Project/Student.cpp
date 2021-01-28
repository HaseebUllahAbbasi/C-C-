#include<iostream>
#include "Student.h"
using namespace std;
void Student::display_student()
{
        cout << "==========================================" << endl;
        cout<<"====Student======"<<endl;
        cout << "first_name : " << first_name << endl;
        cout << "last_name : " << last_name << endl;
        cout << "id : " << id << endl;
        cout << " date_of_birth : " << date_of_birth << endl;
        cout << "standing : " << standing << endl;
        cout << "credit : " << credits << endl;
        cout << "==========================================" << endl;
};
