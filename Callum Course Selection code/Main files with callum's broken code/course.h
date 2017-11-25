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
    bool Scheduled;
    char time;
	
public:
    explicit course(string cID = " ", bool scheduled = false);
    void set_pre_req(string const id );
    void write(ostream &out) const;
    void scheduling(char t);
    void clear_sch();
    string ID_getter(void);
    string preReq_getter(int k);
    int getSizePreReq(void);
};


#endif //MAIN_BODY_COURSE_H
