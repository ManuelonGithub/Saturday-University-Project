//
// Created by manuel on 24/11/17.
//

#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"

#ifndef MAIN_BODY_TERM_OPERATIONS_H
#define MAIN_BODY_TERM_OPERATIONS_H

#endif //MAIN_BODY_TERM_OPERATIONS_H

void time_table_print(vector<course> &courses, int t, ostream &out);  // WIP: Creates a text file for every term processed, and prints out the time table for that semester. See term_operations.cpp line 9 for the function body

bool Scheduler(vector<string> &FUS, vector<course> &total, bool time_slot_toggle, vector<student> &students);

void print_attendance(vector<string> &FUS, vector<course> &total, vector<student> &students, vector <classroom> &classrooms);

string course_selection(vector<course> &available, student &s, bool timing);

int building_manager(vector<course> &total, vector<student> &students, vector <classroom> &classrooms, int term, ostream &timetable);