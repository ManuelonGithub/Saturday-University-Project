//
// Created by manuel on 22/11/17.
//

#include <fstream>
#include <iomanip>
#include <sstream>
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

void courses_read(string Filepath, vector<course> &courses, reg_system &s)
{
    course *c;
    string str;
    int total_courses_given;
    ifstream courses_in;

    courses_in.open(Filepath.c_str());

    if(!courses_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(1);
    }
    else
    {
        getline(courses_in, str);

        total_courses_given = stoi(str);
        if(total_courses_given != s.courses())
        {
            cout << "ERROR: Total courses in course file (" << total_courses_given << ") ";
            cout << "doesn't match the total courses established by the system parameter file (" << s.courses() << ")";
            cout << "\n";

            exit(1);
        }

        while(getline(courses_in, str))
        {
            istringstream ss(str);
            string id;

            ss >> id;
            c = new course(id);

            while(ss >> id)
            {
                c->set_pre_req(id);
            }

            courses.push_back(*c);
        }
    }

}

void print_all_courses(ostream &out, vector<course> c)
{
    for(int i = 0; i < c.size(); i++)
    {
        c[i].write(out);
    }
}

void classrooms_read(string Filepath, vector<classroom> &classrooms, reg_system &s)
{
    ifstream rooms_in;
    int vac, r, rn;

    rooms_in.open(Filepath.c_str());

    if(!rooms_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(1);
    }
    else
    {
        rooms_in >> r;

        s.classrooms(r);

        for(int i = 0; i <= r; i++)
        {
            rn = i;
            rooms_in >> vac;
            classrooms.emplace_back(rn, vac);
        }
    }
}

void print_all_classrooms(ostream &out, vector<classroom> c)
{
    for(int i = 0; i < c.size(); i++)
    {
        c[i].write(out);
    }
}

void students_ini(vector<student> &students, reg_system &s)
{
    for(int i = 1; i <= s.students(); i++)
    {
        students.emplace_back(i);
    }
}

void print_all_students(ostream &out, vector<student> &students)
{
    for(int i=0; i < students.size(); i++)
    {
        students[i].write(out);
    }
}

void clear_for_next_term(vector<course> &courses)
{
    for(int i = 0; i < courses.size(); i++)
    {
        courses[i].clear_sch();
    }
}
