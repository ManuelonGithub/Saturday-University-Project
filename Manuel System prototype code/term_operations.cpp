//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"

void time_table_print(vector<course> &courses, int t)       // WIP: Creates a text file for every term processed, and prints out the time table for that semester
{
    string term = "Term " + to_string((t+1)) + " Time Table.txt";
    ofstream fileout;
    fileout.open(term.c_str());

    fileout << term << "\n\n";

    for (int i = 0; i < courses.size(); i++) {
        if(courses[i].is_scheduled()) {
            fileout << "Course ID: " << courses[i].get_ID() << " - Room: " << courses[i].get_room() << " - Course time: ";
            if(courses[i].course_time() == 'm') {
                fileout << "Morning";
            }
            else if(courses[i].course_time() == 'a') {
                fileout << "Afternoon";
            }
            fileout << "\n\n";
        }
    }

    fileout.close();
}

void time_table_creation_test_1(vector<course> &courses, vector<classroom> &classrooms)     // A test to create a time table
{
    for (int i = 0; i < classrooms.size(); i++)
    {
        if((i % 2) == 0) {
            courses[i].scheduling('m');
        }
        else {
            courses[i].scheduling('a');
        }
        courses[i].set_room(classrooms[i].get_room());
    }
}

void term_completed(vector<student> &grad_st, vector<student> &st, vector<course> &c, vector<string> &sel_cs, reg_system &sys)      // WIP: Funcion to be called at the end of each semester
{
    for(int i = 0; i < st.size(); i++) {
        st[i].complete_courses();
        st[i].graduate(sys.core_courses());
    }
    for(int i = 0; i < c.size(); i++) {
        if(c[i].is_scheduled()) {
            c[i].clear_sch();
        }
    }
    fill(sel_cs.begin(), sel_cs.end(), "");
}