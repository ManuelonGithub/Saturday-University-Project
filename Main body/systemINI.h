//
// Created by Manuel on 21/11/2017.
//
#include <iostream>
#include <fstream>
#include "course.h"
#include "classroom.h"
#include "student.h"

using namespace std;

#ifndef MAIN_BODY_SYSTEMINI_H
#define MAIN_BODY_SYSTEMINI_H

void system_parameters_read(string Filepath, int &st_n, int &t_T, int &t_r_c, int &s_T, int &s_st);

void write_system_parameters(ostream &out, int st_num, int total_T, int total_req_crs, int sample_T, int sample_st);

void courses_read(string Filepath, vector<course> &courses, int &total_courses_given);

void write_all_courses(ostream &out, vector<course> c, int n);

void classrooms_read(string Filepath, vector<classroom> &classrooms, int &total_classrooms);

void students_ini(vector<student> &students, int st_num);

#endif //MAIN_BODY_SYSTEMINI_H
