//
// Created by Manny on 22/11/2017.
//
#include <iostream>
#include <vector>
#include "course.h"
using namespace std;

#ifndef MAIN_BODY_STUDENT_H
#define MAIN_BODY_STUDENT_H

class student {
private:
    int st_ID;
    vector<string>completed_courses;
    string scheduled_courses[2];
    string selected_course;
    int terms_completed;
    bool graduated;

public:
    student(int s_ID = 0, int t_c = 0, bool g = false);
    void term_completed();
    void graduation();
    void set_selected_course(string c);
    int get_id();
    void write(ostream &out) const;
    void schedule(char t, string c);
    string bestChoice(vector<course> &in);
    string attendance(int i);
};

void students_ini(vector<student> &students, int student_count);

void print_all_students(ostream &out, vector<student> &students);

#endif //MAIN_BODY_STUDENT_H
