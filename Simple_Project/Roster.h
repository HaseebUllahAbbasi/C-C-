#include<iostream>
#include "Student.h"

#define Roster_H

#define size_of_roster 10
#define size 50



class Roster
{
public:
    Course course;
    Student *students[size];

    int count;
    Roster();
    void insert(Student *obj);
    void insert(string first_name,string last_name, int credits,int id_1,string standing,string date_of_birth,double gpa);
    void write_data();
    void add_course(int code,string name,string prof_name,int no_of_credits);

    void add_course();
    void remove(int id);
    void update(int id);
    void display_student();
    void display_roster();
};
