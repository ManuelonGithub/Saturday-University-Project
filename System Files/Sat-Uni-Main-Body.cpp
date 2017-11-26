<<<<<<< HEAD:System Files/Sat-Uni-Main-Body.cpp
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
    
    courses_read("courses.txt", courses, sys);
    
    
    //print_all_courses(cout, courses);
    
    //classrooms_read("classrooms.txt", classrooms, sys);
    
    //print_all_classrooms(cout, classrooms);
    
    students_ini(students, sys);
    
    //print_all_students(cout, students);
    
    for (int i = 0; i < 20; i++) {
        FUS.push_back(students[i].bestChoice(courses));
    }
    return 0;
}
=======
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

    sys.create("system-parameters-in.txt");

    //sys.write(cout);

    //courses_read("courses.txt", courses, sys);

    //print_all_courses(cout, courses);

    //classrooms_read("classrooms.txt", classrooms, sys);

    //print_all_classrooms(cout, classrooms);

    students_ini(students, sys);

    print_all_students(cout, students);

    return 0;
}
>>>>>>> d7515b1b0b40a197132c94a94e8f97b9544ca37c:Main body/Sat-Uni-Main-Body.cpp
