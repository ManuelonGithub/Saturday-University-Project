//
// Created by manuel on 24/11/17.
//

#include "course.h"
#include "classroom.h"
#include "student.h"

#ifndef MAIN_BODY_TERM_OPERATIONS_H
#define MAIN_BODY_TERM_OPERATIONS_H

#endif //MAIN_BODY_TERM_OPERATIONS_H

void time_table_print(vector<course> &courses, int t);
void time_table_creation_test_1(vector<course> &courses, vector<classroom> &classrooms);
int calculateTuition(vector<course> &term);
void Scheduler(vector<string> &FUS, vector<course> &total, int timing, vector<student> &students, vector <classroom> &classrooms, int room);
void print_attendance(vector<string> &FUS, vector<course> &total, vector<student> &students, vector <classroom> &classrooms);
