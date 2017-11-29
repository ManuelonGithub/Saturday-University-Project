//
// Created by Manny on 22/11/2017.
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef MAIN_BODY_CLASSROOM_H
#define MAIN_BODY_CLASSROOM_H

class classroom{
private:
    string room_name;   // The classroom's designated name
    int vacancy;        // The vacancy of the classroom
    int capacityMorning;
    int capacityAfternoon;
    string m;
    string a;

public:
    classroom(int r, int vac);          // Class classroom constructor. See classroom.cpp line  for the constructor's body
    int get_maxcap();
    string get_room();                  // Method that retrieves the designated room name. See classroom.cpp line  for the method's body
    void write(ostream &out) const;     // Method that prints the classroom's pertinent information to out. See classroom.cpp line  for the method's body
    void setCourseMorning(string morn, int size);
    void setCourseAfternoon(string aft, int size);
    void printCourses(void);
};

void classrooms_read(string Filepath, vector<classroom> &classrooms);   // Function that takes in the classroom input file and adds the classrooms available to the classrooms vector. See classroom.cpp line 22 for the function's body

void print_all_classrooms(ostream &out, vector<classroom> c);   // Function that prints out all classrooms and their pertinent information. See classroom.cpp line 49 for the function's body

void assign(int r);

#endif //MAIN_BODY_CLASSROOM_H
