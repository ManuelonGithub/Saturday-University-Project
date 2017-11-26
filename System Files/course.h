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
    void set_room(string room);
    void set_pre_req(string const id );
    void write(ostream &out) const;
    void scheduling(char t);
    void clear_sch();
    string get_ID();
    string get_PreReq(int k);
    string get_room();
    char course_time();
    bool is_scheduled();
};

void courses_read(string Filepath, vector<course> &courses, int sys_course_count);

void print_all_courses(ostream &out, vector<course> c);

#endif //MAIN_BODY_COURSE_H
