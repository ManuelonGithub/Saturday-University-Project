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
    char type;
    bool scheduled;
    char time;
    string classroom;
	
public:
    explicit course(string cID = " ", bool scheduled = false);
    void set_pre_req(string const id );
    void set_room(string room);
    bool is_scheduled();
    char course_time();
    int getSizePreReq(void);
    string get_ID();
    string get_pre_req(int k);
    string get_room();
    void write(ostream &out) const;
    void scheduling(char t);
    void clear_sch();
};

void courses_read(string Filepath, vector<course> &courses, int sys_course_count);

void print_all_courses(ostream &out, vector<course> c);


#endif //MAIN_BODY_COURSE_H
