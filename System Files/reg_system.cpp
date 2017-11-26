//
// Created by manuel on 22/11/17.
//

#include <fstream>
#include <iomanip>
#include "reg_system.h"

void reg_system::create(string Filename)
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
    }

    sys_par_in.close();
}

void reg_system::write(ostream &out) const
{
    out << "Number of students in the University: " << setw(7) << student_number << "\n";
    out << "Number of terms to process: " << setw(16) <<  total_terms_to_process << "\n";
    out << "Number of total required courses: " << setw(9) << (total_courses_req-2) << " core courses," << "\n";
    out << setw(43) << 2 << " elective courses," << "\n";
    out << setw(43) << total_courses_req << " overall courses required" << "\n";
    out << "Term to be sampled: " << setw(27) << "Term " << Term_to_Sample<< "\n";
    out << "Student to be sampled: " << setw(28) << "Student #" << Student_to_Sample << "\n";
}

int reg_system::students()          { return student_number; }
int reg_system::terms_to_process()  { return total_terms_to_process; }
int reg_system::courses()           { return total_courses_req; }
int reg_system::Sample_Term()       { return Term_to_Sample; }
int reg_system::Sample_Student()    { return Student_to_Sample; }
void reg_system::classrooms(int r)  { total_classrooms = r; }

/*
void clear_for_next_term(vector<course> &courses)
{
    for(int i = 0; i < courses.size(); i++)
    {
        courses[i].clear_sch();
    }
}
 */