#include <iostream>
#include <vector>
#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"

using namespace std;

int main()
{
    reg_system sys;
    vector<course> courses; 
    vector<classroom> classrooms; 
    vector<student> students;
	vector<string> FUS;
    sys.create("system-parameters-in.txt");

    //sys.write(cout);

    //courses_read("courses.txt", courses, sys);

    //print_all_courses(cout, courses);

    classrooms_read("classrooms.txt", classrooms, sys);

    print_all_classrooms(cout, classrooms);

    //students_ini(students, sys);

    //print_all_students(cout, students);

	//Request a course from the Faculty Of Undergraduate Studies
	for (int i=0; i < students.size(); i++) 
	{
		FUS[i] = students[i].bestChoice(courses);
	}
	
    return 0;
}
