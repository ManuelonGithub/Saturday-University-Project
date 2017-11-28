//
// Created by manuel on 22/11/17.
//

#include <fstream>
#include <iomanip>
#include "reg_system.h"

void reg_system::create(string Filename)    // Method that takes in the system parameter input file and stores the pertinent information for the system
{
    ifstream sys_par_in;

    sys_par_in.open(Filename.c_str());

    if(!sys_par_in)
    {
        cout << "error opening system parameters input file. Make sure the name of the file is: system-parameters-in.txt" << endl;
        exit(1);
    }
    else
    {
        sys_par_in >> student_number;
        sys_par_in >> total_terms_to_process;
        sys_par_in >> total_courses_req;
        sys_par_in >> Term_to_Sample;
        sys_par_in >> Student_to_Sample;
        core_courses_req = (total_courses_req-2);
    }

    sys_par_in.close();
}

void reg_system::write(ostream &out) const      // Method that outputs the registration system parameters
{
    out << "Number of students in the University: " << setw(6) << student_number << "\n";
    out << "Number of terms to process: " << setw(16) <<  total_terms_to_process << "\n";
    out << "Number of total required courses: " << setw(9) << (total_courses_req-2) << " core courses," << "\n";
    out << setw(43) << 2 << " elective courses," << "\n";
    out << setw(43) << total_courses_req << " overall courses required" << "\n";
    out << "Term to be sampled: " << setw(27) << "Term " << Term_to_Sample<< "\n";
    out << "Student to be sampled: " << setw(28) << "Student #" << Student_to_Sample << "\n\n";
}

int reg_system::students()          { return student_number; }              // Method that retrieves the number of students attending the university
int reg_system::terms_to_process()  { return total_terms_to_process; }      // Method that retrieves the number of terms the system needs to process
int reg_system::courses()           { return total_courses_req; }           // Method that retrieves the total amount of courses required for a student to graduate
int reg_system::core_courses()      { return core_courses_req; }            // Method that retrieves the total amount of core courses required for a student to graduate
int reg_system::Sample_Term()       { return Term_to_Sample; }              // Method that retrieves the term # needed to be sampled
int reg_system::Sample_Student()    { return Student_to_Sample; }           // Method that retrieves the student # that the system needs to sample
void reg_system::set_classrooms(int r)  { total_classrooms = r; }           // Method that sets the total amount of classrooms available to assign to the courses