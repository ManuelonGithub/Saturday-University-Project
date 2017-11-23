//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

student::student(int s_ID, int t_c, bool g)
{
    st_ID = s_ID;
    terms_completed = t_c;
    graduated = g;
}

void student::term_completed()  { terms_completed++; }
void student::graduation()      { graduated = true; }

void student::write(ostream &out) const
{
    out << "Student " << "B" << st_ID << ": " << "\n";
    out << setw(23) << "Graduated? ";
    if(graduated)
        out << "Y";
    else
        out<< "N";
    out << "\n";
    out << setw(29) << "Terms Completed: " << terms_completed << "\n";
    out << setw(31) << "Courses Completed: ";
    if(completed_courses.empty())
    {
        out << "None";
    }
    else
    {
        for (const auto &i : completed_courses) {
            out << i << ", ";
        }
    }
    out << "\n\n";
}