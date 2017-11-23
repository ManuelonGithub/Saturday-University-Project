//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef MAIN_BODY_COURSE_H
#define MAIN_BODY_COURSE_H

class course
{
private:
    string courseID;
    vector<string> pre_req;

public:
    explicit course(string cID = " ");
    void set_pre_req(string const id );
    void write(ostream &out) const;
};


#endif //MAIN_BODY_COURSE_H
