#include<iostream>
#include "Roster.h"

using namespace std;

void Course::display_course_data()
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

Roster::Roster()
{
	count = 0;
};
void Roster:: insert(Student *obj)
{
        students[count++] = obj;
};
void Roster ::insert(string first_name,string last_name, int credits,int id_1,string standing,string date_of_birth,double gpa)
{

        students[count] = new Student();
        students[count]->first_name = first_name;
        students[count]->last_name =  last_name;
        students[count]->credits = credits;
        students[count]->date_of_birth = date_of_birth;
        students[count]->gpa = gpa;
        students[count]->standing = standing;
        students[count]->id = id_1;
        count++;

};
void Roster:: write_data()
{
	ofstream writer("roster.txt");
        writer<<course.name<<" | "<<course.code<<" | "<<course.no_of_credits<<" | "<<course.prof_name<<endl;
        for(int i=0; i<count; i++)
        {
            writer<<students[i]->first_name<<" | "<<students[i]->last_name<<" | "<<students[i]->id<<" | "<<students[i]->standing<<" | "<<students[i]->credits<<" | "<<students[i]->gpa<<" | "<<students[i]->date_of_birth<<endl;
        }
        writer<<"end_roster";
        writer.close();



};
void Roster::add_course(int code,string name,string prof_name,int no_of_credits)
{

        course.code = code;
        course.name = name;
        course.prof_name = prof_name;
        course.no_of_credits = no_of_credits;
};

void Roster :: remove(int id)
{

        for (int i = 0; i < count; i++)
        {
            if (students[i] != NULL)
                if (students[i]->id == id)
                {
                    students[i] = NULL;
                    cout<<"student deleted"<<endl;
                    return;
                }
        }
        cout<<"student not deleted"<<endl;
};
void update(int id)
{
	for (int i = 0; i < count; i++)
        {
            if(students[i] != NULL)
                if (students[i]->id == id)
                {
                    cout << "Please enter the first name" << endl;
                    cin >> students[i]->first_name;
                    cout << "Please enter the last name" << endl;
                    cin >> students[i]->last_name;
                    cout << "please enter the id" << endl;
                    cin >> students[i]->id;
                    cout << "please enter the gpa" << endl;
                    cin >> students[i]->gpa;
                    cout << "please enter the standing" << endl;
                    cin >> students[i]->standing;
                    cout << "please enter the DOB" << endl;
                    cin >> students[i]->date_of_birth;
                    cout << "data updated" << endl;
                    return;
                }
        }
        cout<<"not updated"<<endl;
};
void Roster:: display_student()
{
        cout << "****************************************" << endl;
        for (int i = 0; i < count; i++)
        {
            if (students[i] != NULL)
                students[i]->display_student();
        }
        cout << "****************************************" << endl;
};
void Roster ::display_roster()
{
        course.display_course_data();
        cout << "****************************************" << endl;
        for (int i = 0; i < count; i++)
        {
            if (students[i] != NULL)
                students[i]->display_student();
        }
        cout << "****************************************" << endl;
};
