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
    string room_name;
    int vacancy;
    int capacity;
    string m;
    string a;
public:
    classroom(int r, int vac);
    void write(ostream &out) const;
    string get_room();
    void setCourseMorning(string morn);
    void setCourseAfternoon(string aft);

};

void classrooms_read(string Filepath, vector<classroom> &classrooms);
void assign(int r);
void print_all_classrooms(ostream &out, vector<classroom> c);

#endif //MAIN_BODY_CLASSROOM_H
