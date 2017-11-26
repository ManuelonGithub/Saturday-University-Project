//
// Created by Manuel on 22/11/2017.
//

#include <iostream>
#include <vector>
#include "course.h"

using namespace std;

course::course(string cID, bool scheduled)  { courseID = cID; }
void course::set_pre_req(string const id)   { pre_req.push_back(id);}
string course::ID_getter(void)              { return courseID; }
string course::getPreReq(int k)             { return pre_req[k]; }
int course::getSizePreReq(void)             { return pre_req.size(); }

void course::write(ostream &out) const
{
    out << courseID << ": " << "\n";
    if(!pre_req.empty()) {
        out << "\tpre-requisite courses: ";
        for (const auto &i : pre_req) {
            out << i << ", ";
        }
        out << "\n";
    }
    else  {
        out << "\tNo pre-requisite courses \n";
    }

}

void course::scheduling(char t)
{
    if (t == 'M' or 'A' or 'm' or 'a') {
        time = t;
        Scheduled = true;
    }
}

void course::clear_sch()
{
    Scheduled = false;
    time = ' ';
}

//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <iomanip>
#include "student.h"

#include <time.h>
#include <cstdlib>

using namespace std;

student::student(int s_ID, int t_c, bool g)
{
    st_ID = s_ID;
    terms_completed = t_c;
    graduated = g;
}

void student::term_completed() 				{ terms_completed++; }
void student::graduation() 					{ graduated = true; }
void student::set_selected_course(string c) { selected_course = c; }

void student::write(ostream &out) const
{
    out << "Student " << "B" << st_ID << ": " << "\n";
    out << setw(23) << "Graduated? ";
    if(graduated) {
        out << "Y";
    }
    else {
        out<< "N";
    }
    out << "\n";
    
    out << setw(29) << "Terms Completed: " << terms_completed << "\n";
    out << setw(31) << "Courses Completed: ";
    
    if(completed_courses.empty()) {
        out << "None";
    }
    else {
        for(int i = 0; i < terms_completed; i++)
        {
            out << completed_courses[i];
        }
    }
    out << "\n\n";
}

void student::schedule(char t, string c)
{
    if(t == 'M' or 'm')  {
        scheduled_courses[0] = c;
    }
    else if(t == 'A' or 'a') {
        scheduled_courses[1] = c;
    }
}

string student :: bestChoice(vector<course> &available){
    
    int preReqDone;
    vector<string> past; // the courses the student has gotten on each iteration of the FUS
    vector<course> option;// new array of possibilities (never taken, has pre reqs, not scheduled already)
    
    
    for (int i=0; i < available.size(); i++)
    {
        preReqDone=0;
        for (int k=0; k < completed_courses.size(); k++)
        {
            if (available[i].ID_getter() != completed_courses[k]) // if the student has course already, not an option
            {
                for (int h=0; h < available[i].getSizePreReq(); h++)
                {
                    if (available[i].getPreReq(h) == completed_courses[k])
                    {
                        preReqDone++; // number of prerequisites filled is increased
                    }
                }
            }
        }
        if (preReqDone >= available[i].getSizePreReq())
        {
            option.push_back(available[i]);
        }
    }
    
    //Pick a random integer between 0 and number of option courses
    int ran;
    ran = rand() % option.size();
    string bestChoice;	
    bestChoice = option[ran].ID_getter();
    past.push_back(bestChoice);//Storing the student's wish for each iteration
    
    cout<< "The FUS has selected course " << bestChoice << " for the student B" << st_ID << endl;
    return bestChoice;
}

