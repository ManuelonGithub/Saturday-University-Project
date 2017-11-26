//
// Created by manuel on 22/11/17.
//

#include <iostream>
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
    void classrooms(int r);
    int students();
    int terms_to_process();
    int courses();
    int Sample_Term();
    int Sample_Student();
};

//void clear_for_next_term(vector<course> &courses);

#endif //MAIN_BODY_SYSTEM_H
