#include <iostream>
#include <list>
#include <fstream>
#include "Roster.h"
using namespace std;
void show_menu_Super()
{
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout << "1: Create a new Roster " << endl;
    cout << "2: Drop a Roster " << endl;
    cout << "3: Display Roster information " << endl;
    cout << "4: Display All Rosters " << endl;
    cout << "5: Select Roster to do operations " << endl;
    cout<<  "6: EXIT "<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
void show_user()
{
    cout<<"#######################################"<<endl;
    cout << "Please enter  below options " << endl;

    cout << "1: SuperVisor Mode" << endl;
    cout << "2: User Mode" << endl;
    cout<<"#######################################"<<endl;
}
bool authenticate()
{

    string user_name;
    string password;
    string input_user_name;
    string input_password;
    cout<<"enter the user name"<<endl;
    cin >> user_name;
    cout<<"enter the password"<<endl;
    cin >> password;


    ifstream reader("database.txt");
    reader >> input_user_name;
    reader >> input_password;

    reader.close();
    if (input_password == password && user_name == input_user_name)
        return true;
    return false;

    //return true;
}
int main()
{

    Roster *roster[size_of_roster];
    int index = 0;
    int choice = 0;
    goto load_roster;
    load_roster:
    {
        ifstream read("roster.txt");
        while(!read.eof())
        {
            string temp;
            string name,prof_name;
            int course_credits,code;
            read>>name;
            if(name=="")
                break;
            read>>temp>>code>>temp>>course_credits>>temp>>prof_name;
          //  cout<<name<<code<<course_credits<<prof_name<<endl;

            roster[index] = new Roster();
            roster[index]->add_course(code,name,prof_name,course_credits);

            string temp_1;
            read>>temp_1;
            while(temp_1!="end_roster")
            {
                string first_name, last_name,standing,date_of_birth;
                int id,credits;
                double gpa;
                read>>temp>>last_name>>temp>>id>>temp>>standing>>temp>>credits>>temp>>gpa>>temp>>date_of_birth;
                roster[index]->insert(temp_1,last_name,credits,id,standing,date_of_birth,gpa);
                read>>temp_1;

            }
            index++;
        }
        //read.close();

    }

    while (true)
    {
        show_user();
        cin >> choice;
        if (choice == 1 || choice == 2)
            break;
    }
    if (choice == 1)
    {
        cout << "Welcome to Supervisor Mode" << endl;

        if (authenticate())
        {
            cout << "login successful" << endl;
            while (true)
            {
                int choice_user;
                show_menu_Super();
                cin >> choice_user;
                if (choice_user == 1)
                {
                    roster[index] = new Roster();
                    roster[index++]->add_course();
                    cout<<"course entered"<<endl;
                }
                else if (choice_user == 2)
                {
                    cout << "enter course number to drop" << endl;
                    int course_no;
                    cin >> course_no;

                    for (int i = 0; i < index; i++)
                    {

                        if (roster[i] != NULL)
                            if (roster[i]->course.code == course_no)
                            {
                                roster[i] == NULL;
                                cout<<"course deleted"<<endl;
                            }
                    }
                }
                else if (choice_user == 3)
                {
                    cout << "enter course number" << endl;
                    int course_no;
                    cin >> course_no;

                    for (int i = 0; i < index; i++)
                    {

                        if (roster[i] != NULL)
                            if (roster[i]->course.code == course_no)
                            {
                                cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                                roster[i]->display_roster();
                                cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
                            }
                    }
                }
                else if (choice_user == 4)
                {
                    cout << "All Rosters" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        if (roster[i] != NULL)
                        {
                            cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                            roster[i]->display_roster();
                            cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
                        }
                    }
                }
                else if (choice_user == 5)
                {
                    int index_of_roster;
                    cout << "there are " << index << " roster" << endl;
                    if (index > 0)
                    {

                        cout << "select a roster " << endl;
                        cin >> index_of_roster;
                        if (index_of_roster <= index)
                        {
                            int choice_of_roster_item;
                            cout << "1 : Insert new Student to a Roster" << endl;
                            cout << "2 : Remove a Student from a Roster" << endl;
                            cout << "3 : Update a Student in a Roster" << endl;
                            cout << "4 : List all Students in one Roster in sorted order" << endl;
                            cin >> choice_of_roster_item;
                            if (choice_of_roster_item == 1)
                            {
                                Student *obj = new Student();
                                cout << "Please enter the first name" << endl;
                                cin >> obj->first_name;
                                cout << "Please enter the last name" << endl;
                                cin >> obj->last_name;
                                cout << "please enter the id" << endl;
                                cin >> obj->id;
                                cout << "please enter the gpa" << endl;
                                cin >> obj->gpa;
                                cout << "please enter the standing" << endl;
                                cin >> obj->standing;
                                cout<< "please enter the credits"<<endl;
                                cin>>obj->credits;
                                cout << "please enter the DOB" << endl;
                                cin >> obj->date_of_birth;
                                roster[index_of_roster]->insert(obj);
                            }
                            else if (choice_of_roster_item == 2)
                            {
                                cout << "enter the id to remove" << endl;
                                int id;
                                roster[index_of_roster]->remove(id);
                            }
                            else if (choice_of_roster_item == 3)
                            {

                                cout << "enter the id to remove" << endl;
                                int id;
                                cin>>id;
                                roster[index_of_roster]->update(id);
                            }
                            else if(choice_of_roster_item==4)
                            {
                                for(int i=0; i<roster[index_of_roster]->count; i++)
                                {
                                    roster[i]->display_student();
                                }
                            }
                            else if(choice_of_roster_item==5)
                            {
                                cout<<"exiting program"<<endl;
                                break;
                            }
                        }
                    }
                }
                else if(choice_user==6)
                {
                    cout<<"exiting program"<<endl;
                    break;
                }
            }
        }
        else
        {
            cout << "login failed" << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Welcome to User Mode" << endl;
        while (true)
        {
               int index_of_roster;
                    cout << "there are " << index << " roster" << endl;
                    if (index > 0)
                    {

                        cout << "select a roster " << endl;
                        cin >> index_of_roster;
                        if (index_of_roster <= index)
                        {
                            int choice_of_roster_item;
                            cout << "1 : Insert new Student to a Roster" << endl;
                            cout << "2 : Remove a Student from a Roster" << endl;
                            cout << "3 : Update a Student in a Roster" << endl;
                            cout << "4 : List all Students in one Roster in sorted order" << endl;
                            cout << "5 : Exit "<<endl;

                            cin >> choice_of_roster_item;
                            if (choice_of_roster_item == 1)
                            {
                                Student *obj = new Student();
                                cout << "Please enter the first name" << endl;
                                cin >> obj->first_name;
                                cout << "Please enter the last name" << endl;
                                cin >> obj->last_name;
                                cout << "please enter the id" << endl;
                                cin >> obj->id;
                                cout << "please enter the gpa" << endl;
                                cin >> obj->gpa;
                                cout << "please enter the standing" << endl;
                                cin >> obj->standing;
                                cout << "please enter the DOB" << endl;
                                cin >> obj->date_of_birth;
                                roster[index_of_roster]->insert(obj);
                            }
                            else if (choice_of_roster_item == 2)
                            {
                                cout << "enter the id to remove" << endl;
                                int id;
                                roster[index_of_roster]->remove(id);
                            }
                            else if (choice_of_roster_item == 3)
                            {
                                cout << "to update the data" << endl;
                            }
                            else if(choice_of_roster_item==4)
                            {
                                for(int i=0; i<roster[index_of_roster]->count; i++)
                                {
                                    roster[i]->display_student();
                                }
                            }
                            else if(choice_of_roster_item==5)
                            {
                                cout<<"exiting program"<<endl;
                                break;
                            }
                        }
                    }

        }
    }
    for(int i=0; i<index; i++)
    {
        roster[i]->write_data();
    }
}
