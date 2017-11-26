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
<<<<<<< HEAD:Callum Course Selection code/Main files with callum's broken code/course.h
	
=======

>>>>>>> d7515b1b0b40a197132c94a94e8f97b9544ca37c:Main body/course.h
public:
    explicit course(string cID = " ", bool scheduled = false);
    void set_pre_req(string const id );
    void write(ostream &out) const;
    void scheduling(char t);
    void clear_sch();
<<<<<<< HEAD:Callum Course Selection code/Main files with callum's broken code/course.h
    string ID_getter(void);
    string getPreReq(int k);
    int getSizePreReq(void);
=======
>>>>>>> d7515b1b0b40a197132c94a94e8f97b9544ca37c:Main body/course.h
};


#endif //MAIN_BODY_COURSE_H
