//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"

void time_table_print(vector<course> &courses, int t)
{
    string term = "Term " + to_string((t+1)) + " Time Table.txt";
    ofstream fileout;
    fileout.open(term.c_str());

    fileout << term << "\n\n";

    for (int i = 0; i < courses.size(); i++) {
        if(courses[i].is_scheduled())
        {
            fileout << "Course ID: " << courses[i].get_ID() << " - Room: " << courses[i].get_room() << " - Course time: ";
            if(courses[i].course_time() == 'm'){
                fileout << "Morning";
            }
            else if(courses[i].course_time() == 'a'){
                fileout << "Afternoon";
            }
            fileout << "\n\n";
        }
    }

    fileout.close();
}

void time_table_creation_test_1(vector<course> &courses, vector<classroom> &classrooms)
{
    for (int i = 0; i < classrooms.size(); i++)
    {
        if((i % 2) == 0)  {
            courses[i].scheduling('m');
        }
        else  {
            courses[i].scheduling('a');
        }
        courses[i].set_room(classrooms[i].get_room());
    }
}