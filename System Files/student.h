//
// Created by Manny on 22/11/2017.
//
#include <iostream>
#include <vector>
using namespace std;

#ifndef MAIN_BODY_STUDENT_H
#define MAIN_BODY_STUDENT_H

class student {
private:
    int st_ID;                          // Student ID
    vector<string>completed_courses;    // A vector containing all course IDs the student has completed
    string m_class;                     // A variable that stores the morning class ID of the student for the current term
    string a_class;                     // A variable that stores the afternoon class ID of the student for the current term
    string selected_course;             // The course selected by the FUS for the student to take
    int terms_completed;                // Variable that stores how many terms the student has completed
    int core_courses_completed;         // Variable that stores how many core courses the student has completed
    int elective_courses_completed;     // Variable that stores how many elective courses a student has completed
    bool grad;                          // Boolean entity that determines if a student has graduated or not

public:
    student(int s_ID, int t_c = 0, bool g = false);     // Class student constructor. see student.cpp line 8 for the constructor's body
    void term_completed();                              // Method that increments the amount of terms completed. see student.cpp line 16 for the method's body
    void set_selected_course(string c);                 // Method that sets the selected course for the student. see student.cpp line 17 for the method's body
    int get_id();                                       // Method that retrieves the student's ID. see student.cpp line 18 for the method's body
    bool graduated();                                   // Method that checks if the student has graduated (true) or not (false). see student.cpp line 19 for the method's body
    void write(ostream &out) const;                     // Method that prints pertinent student information to out. see student.cpp line 21 for the method's body
    void schedule(char t);                              // Method that schedules the selected courses of the student to the morning of afternoon class slot for the student. see student.cpp line 49 for the method's body
    string attendance();
    void complete_courses();                            // Method that transfers the student's scheduled courses for that semester to the completed courses vector. see student.cpp line 99 for the method's body
    void graduate(int core);                            // Method that determines if the student graduates or not. see student.cpp line 124 for the method's body
    bool needs_mor_course();
    bool needs_aft_course();
    bool completed_course(string course);
    string mor_course();
    string aft_course();
};

void students_ini(vector<student> &students, int student_count);

void print_all_students(ostream &out, vector<student> &students);

#endif //MAIN_BODY_STUDENT_H
