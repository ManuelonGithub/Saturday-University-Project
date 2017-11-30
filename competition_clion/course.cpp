//
// Created by Manuel on 22/11/2017.
//
#include <iomanip>
#include <fstream>
#include <sstream>
#include "course.h"

course::course(string cID, bool scheduled)
{
    courseID = cID;
    type = courseID[0];
    k_value=0;
}

void course::set_pre_req(string const id)   { pre_req.push_back(id);}                       // Method that adds a course ID to the pre-requisite vector that each course contains
bool course::is_scheduled()                 { return scheduled; }                           // Method that checks if the course has been scheduled for the current term
int course::getSizePreReq()                 { return static_cast<int>(pre_req.size()); }    // Method that retrieves how many pre-requisite courses the course has
string course::get_ID()                     { return courseID; }                            // Method that retrieves the course ID
string course::get_pre_req(int k)           { return pre_req[k]; }                          // Method that retrieves a course ID from the pre-req vector of the course

void course::inc_k_value() {
    k_value++;
    cout << courseID << " is a prereq for " << k_value << " class(es)" << endl;
}

void course::schedule() { scheduled = true; }     // Method that schedules the course to its designated time slot
void course::clear_sch() { scheduled = false; }
int course::get_k_value() { return k_value; }


void courses_read(string Filepath, vector<course> &courses)     // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector
{
    course *c;
    string str;
    ifstream courses_in;

    courses_in.open(Filepath.c_str());

    if(!courses_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(1);
    }
    else
    {
        getline(courses_in, str);

        while(getline(courses_in, str))
        {
            istringstream ss(str);
            string id;

            ss >> id;
            c = new course(id);

            while(ss >> id)
            {
                c->set_pre_req(id);
            }

            courses.push_back(*c);
        }
    }

    courses_in.close();
}

scheduled_course::scheduled_course(const string &id, char t, int num)
{
    courseID = id;
    time = t;
    student_attending = num;
}

void scheduled_course::set_room(string room)    { classroom = room; }
void scheduled_course::set_students(int n)      { student_attending = n; }
int scheduled_course::get_students()            { return student_attending; }
string scheduled_course::get_room()             { return classroom; }
char scheduled_course::get_time()               { return time; }

void scheduled_course::write(ostream &out)
{
    out << "Course_ID: " << courseID << "\t-\t" << "time slot assigned";
    if(time == 'm') {
        out << " Morning";
    }
    else {
        out << " Afternoon";
    }
    out << "\t-\t" << "Students Registered for the course: " << student_attending << "\n";
}

