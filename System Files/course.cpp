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
}
void course::set_pre_req(string const id)   { pre_req.push_back(id);}
void course::set_room(string room)          { classroom = room; }
bool course::is_scheduled()                 { return scheduled; }
char course::course_time()                  { return time; }
int  course::getSizePreReq(void)            { return pre_req.size(); }
string course::get_room()                   { return classroom; }
string course::get_ID()                     { return courseID; }
string course::get_pre_req(int k)            { return pre_req[k]; }


void course::write(ostream &out) const
{
    out << courseID << ": " << "\n";

    if(!pre_req.empty()) {
        out << setw(27) <<"pre-requisite courses: ";
        for (const auto &i : pre_req) {
            out << i << ", ";
        }
        out << "\n";
    }
    else  {
        out << setw(29) << "No pre-requisite courses\n";
    }

    out << setw(17) << "Course Type: ";
    if(type == 'c') {
        out << "Core ";
    }
    else if(type == 'e'){
        out << "Elective";
    }
    out << "\n\n";
}

void course::scheduling(char t)
{
    time = t;
    scheduled = true;
    cout << "The course " << courseID << " just got scheduled in the " << time << endl;
}

void course::clear_sch()
{
    scheduled = false;
    time = ' ';
}

void courses_read(string Filepath, vector<course> &courses, int sys_course_count)
{
    course *c;
    string str;
    int total_courses_given;
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

        total_courses_given = stoi(str);
        if(total_courses_given != sys_course_count)
        {
            cout << "ERROR: Total courses in course file (" << total_courses_given << ") ";
            cout << "doesn't match the total courses established by the system parameter file (" << sys_course_count << ")";
            cout << "\n";

            exit(1);
        }

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

void print_all_courses(ostream &out, vector<course> c)
{
    for(int i = 0; i < c.size(); i++)
    {
        c[i].write(out);
    }
}




