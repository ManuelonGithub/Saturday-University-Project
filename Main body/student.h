//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#ifndef MAIN_BODY_STUDENT_H
#define MAIN_BODY_STUDENT_H


class student {
private:
    int st_ID;
    vector<string> completed_courses;
    int terms_completed;
    bool graduated;

public:
    student(int s_ID = 0, int t_c = 0, bool g = false);
};
#endif //MAIN_BODY_STUDENT_H
