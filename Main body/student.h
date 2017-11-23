//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <vector>
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
    void term_completed();
    void graduation();
    void write(ostream &out) const;
};
#endif //MAIN_BODY_STUDENT_H
