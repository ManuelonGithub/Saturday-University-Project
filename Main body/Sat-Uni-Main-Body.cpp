#include <iostream>
#include <vector>
#include "systemINI.h"
#include "course.h"
#include "classroom.h"
#include "student.h"

using namespace std;

int main()
{
    vector<course> courses;
    vector<classroom> classrooms;
    vector<student> students;

    int st_num;				// Total number of students going into the University
    int total_T;			// Total amount of terms we're going to process
    int total_req_crs;		// Core courses + 2 electives
    int sample_T;
    int sample_st;
    int total_courses_given;
    int total_classrooms;

    system_parameters_read("system-parameters-in.txt", st_num, total_T, total_req_crs, sample_T, sample_st);

    write_system_parameters(cout, st_num, total_T, total_req_crs, sample_T, sample_st);

    courses_read("courses.txt", courses, total_courses_given);

    //write_all_courses(cout, courses, total_courses_given);

    //classrooms_read("classrooms.txt", classrooms, total_classrooms);

    //students_ini(students, st_num);

    return 0;
}
