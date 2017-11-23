//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "systemINI.h"

using namespace std;

void system_parameters_read(string Filepath, int &st_n, int &t_T, int &t_r_c, int &s_T, int &s_st)
{
    ifstream sys_par_in;

    sys_par_in.open(Filepath.c_str());

    if(!sys_par_in)
    {
        cout << "error opening system parameters input file. Make sure the name of the file is: system-parameters-in.txt" << endl;
        exit(0);
    }
    else
    {
        sys_par_in >> st_n;
        sys_par_in >> t_T;
        sys_par_in >> t_r_c;
        sys_par_in >> s_T;
        sys_par_in >> s_st;
    }
}

void write_system_parameters(ostream &out, int st_num, int total_T, int total_req_crs, int sample_T, int sample_st)
{
    out << "Number of students in the University: " << "\t" << st_num << "\n";
    out << "Number of terms to process: " << "\t\t\t" <<  total_T << "\n";
    out << "Number of total required courses: " << "\t\t" << (total_req_crs-2) << " core courses, \n";
    out << "\t\t\t\t\t\t\t\t\t\t" << "2 elective courses, \n";
    out << "\t\t\t\t\t\t\t\t\t\t" << total_req_crs << " overall courses required" << "\n";
    out << "Term to be sampled: " << "\t\t\t\t\t" << "Term " << sample_T << "\n";
    out << "Student to be sampled: " << "\t\t\t\t\t" << "Student #" << sample_st << "\n";
}

void courses_read(string Filepath, vector<course> &courses, int &total_courses_given)
{
    course *c;
    string str;
    ifstream courses_in;

    courses_in.open(Filepath.c_str());

    if(!courses_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(0);
    }
    else
    {
        getline(courses_in, str);

        total_courses_given = stoi(str);

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

void write_all_courses(ostream &out, vector<course> c, int n)
{
    for(int i = 0; i <= n; i++)
    {
        c[i].write(out);
    }
}

void classrooms_read(string Filepath, vector<classroom> &classrooms, int &total_classrooms)
{
    ifstream rooms_in;
    string name;
    int vac;

    rooms_in.open(Filepath.c_str());
    if(!rooms_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(0);
    }
    else
    {
        rooms_in >> total_classrooms;

        for(int i = 0; i <= total_classrooms; i++)
        {
            name = "R" + i;
            rooms_in >> vac;
            classrooms.push_back(classroom(name, vac));
        }
    }
}

void students_ini(vector<student> &students, int st_num)
{

}