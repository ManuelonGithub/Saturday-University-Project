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

void time_table_print(vector<course> &courses, int t);  // WIP: Creates a text file for every term processed, and prints out the time table for that semester. See term_operations.cpp line 9 for the function body

void time_table_creation_test_1(vector<course> &courses, vector<classroom> &classrooms);    // A test to create a time table. See term_operations.cpp line 33 for the function body

int calculateTuition(vector<course> &term);

void Scheduler(vector<string> &FUS, vector<course> &total, int timing, vector<student> &students, vector <classroom> &classrooms, int room);

void print_attendance(vector<string> &FUS, vector<course> &total, vector<student> &students, vector <classroom> &classrooms);

void term_completed(vector<student> &grad_st, vector<student> &st, vector<course> &c, vector<string> &sel_cs, reg_system &sys); // WIP: Funcion to be called at the end of each semester. See term_operations.cpp, Line 47 for the function body

int building_manager(vector<course> &total, vector<student> &students, vector <classroom> &classrooms, int term);
