//
// Created by manuel on 22/11/17.
//

#include <iostream>
#include "course.h"
#include "classroom.h"
#include "student.h"

using namespace std;

#ifndef MAIN_BODY_SYSTEM_H
#define MAIN_BODY_SYSTEM_H


class reg_system {
private:
    int student_number;
    int total_terms_to_process;
    int total_courses_req;
    int Term_to_Sample;
    int Student_to_Sample;
    int total_classrooms;

public:
    void create(string Filename);
    void write(ostream &out) const;
    int students();
    int terms_to_process();
    int courses();
    int Sample_Term();
    int Sample_Student();
    void classrooms(int r);
};

void courses_read(string Filepath, vector<course> &courses, reg_system &s);

void print_all_courses(ostream &out, vector<course> c);

void classrooms_read(string Filepath, vector<classroom> &classrooms, reg_system &s);

void print_all_classrooms(ostream &out, vector<classroom> c);

void students_ini(vector<student> &students, reg_system &s);

void print_all_students(ostream &out, vector<student> &students);

#endif //MAIN_BODY_SYSTEM_H
