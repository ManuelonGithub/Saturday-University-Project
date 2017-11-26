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
    void write(ostream &out) const;
    void schedule(char t, string c);
    void set_selected_course(string c);
<<<<<<< HEAD:Callum Course Selection code/Main files with callum's broken code/student.h
    string bestChoice(vector<course> &in);
=======
>>>>>>> d7515b1b0b40a197132c94a94e8f97b9544ca37c:Main body/student.h
};
#endif //MAIN_BODY_STUDENT_H
