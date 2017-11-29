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
    string courseID;            // Course ID
    string classroom;           // The classroom name assigned to this class during the term
    vector<string> pre_req;     // Course's pre-requisite course IDs
    bool scheduled;             // Boolean entity determining if the course has been scheduled for the term
    char type;                  // Variable that stores whether the course is core or elective ('c' or 'e')
    char time;                  // Variable that stores whether the course has been assigned to the morning slot or afternoon slot ('m' or 'a')
    int occupancy;              // The amount of students attending the course for the term
	
public:
    explicit course(string cID, bool scheduled = false);    // Class course constructor. See course.cpp line 9 for the constructor's body
    void set_pre_req(string const id );                     // Method that adds a course ID to the pre-requisite vector that each course contains. See course.cpp line 15 for the Method's body
    void set_room(string room);                             // Method that sets the assigned room for the course during the current term. See course.cpp line 16 for the Method's body
    void set_ID(string id);
    bool is_scheduled();                                    // Method that checks if the course has been scheduled for the current term. See course.cpp line 17 for the Method's body
    char course_time();                                     // Method that checks the time slot assigned to the course. See course.cpp line 18 for the Method's body
    int getSizePreReq();                                    // Method that retrieves how many pre-requisite courses the course has. See course.cpp line 19 for the Method's body
    string get_room();                                      // Method that retrieves the assigned room for the course during the current term. See course.cpp line 20 for the Method's body
    string get_ID();                                        // Method that retrieves the course ID. See course.cpp line 21 for the Method's body
    string get_pre_req(int k);                              // Method that retrieves a course ID from the pre-req vector of the course. See course.cpp line 22 for the Method's body
    void write(ostream &out) const;                         // Method that prints pertinent information of the course to out. See course.cpp line 25 for the Method's body
    void scheduling(char t);                                // Method that schedules the course to its designated time slot. See course.cpp line 50 for the Method's body
    void clear_sch();                                       // Method that clears out the information that was only pertinent for the past term. See course.cpp line 9 for the Method's body
};

void courses_read(string Filepath, vector<course> &courses);    // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector. See course.cpp line 64 for the function's body

void print_all_courses(ostream &out, vector<course> c);         // Funciton that prints out all courses offered by the university and their pertinent information to out. See course.cpp line 101 for the function's body.

#endif //MAIN_BODY_COURSE_H
