//
// Created by manuel on 22/11/17.
//

#include <iostream>
using namespace std;

#ifndef MAIN_BODY_SYSTEM_H
#define MAIN_BODY_SYSTEM_H


class reg_system {
private:
    int student_number;             // The number of students attending the university
    int total_terms_to_process;     // The number of terms the system needs to process
    int total_courses_req;          // The total amount of courses required for a student to graduate (core courses needed + 2 electives)
    int core_courses_req;           // The total amount of core courses required for a student to graduate
    int Term_to_Sample;             // The term # needed to be sampled for the time table (possibly more)
    int Student_to_Sample;          // The student # that the system needs to sample for all course selection
    int total_classrooms;           // The total amount of classrooms available to assign to the courses

public:
    void create(string Filename);       // Method that takes in the system parameter input file and stores the pertinent information for the system. See reg_system.cpp line 9 for the method's body
    void write(ostream &out) const;     // Method that outputs the registration system parameters. See reg_system.cpp line 33 for the method's body
    int students();                     // Method that retrieves the number of students attending the university. See reg_system.cpp line 44 for the method's body
    int terms_to_process();             // Method that retrieves the number of terms the system needs to process. See reg_system.cpp line 45 for the method's body
    int courses();                      // Method that retrieves the total amount of courses required for a student to graduate. See reg_system.cpp line 46 for the method's body
    int core_courses();                 // Method that retrieves the total amount of core courses required for a student to graduate. See reg_system.cpp line 47 for the method's body
    int Sample_Term();                  // Method that retrieves the term # needed to be sampled. See reg_system.cpp line 48 for the method's body
    int Sample_Student();               // Method that retrieves the student # that the system needs to sample. See reg_system.cpp line 49 for the method's body
    void set_classrooms(int r);         // Method that sets the total amount of classrooms available to assign to the courses. See reg_system.cpp line 50 for the method's body
};

#endif //MAIN_BODY_SYSTEM_H