//
// Created by Manuel on 22/11/2017.
//
#include <iomanip>
#include "student.h"
#include <ctime>

student::student(int s_ID, int t_c, bool g)
{
	st_ID = s_ID;
	terms_completed = t_c;
	graduated = g;
}

void student::term_completed() 				{ terms_completed++; }
void student::graduation() 					{ graduated = true; }
void student::set_selected_course(string c) { selected_course = c; }
int student::get_id()                       { return st_ID; }

void student::write(ostream &out) const
{
	out << "Student " << "B" << st_ID << ": " << "\n";
	out << setw(23) << "Graduated? ";
	if(graduated) {
		out << "Y";
	}
	else {
		out<< "N";
	}
	out << "\n";

	out << setw(29) << "Terms Completed: " << terms_completed << "\n";
	out << setw(31) << "Courses Completed: ";

	if(completed_courses.empty()) {
		out << "None";
	}
	else {
		for(int i = 0; i < terms_completed; i++)
		{
		out << completed_courses[i];
		}
	}
	out << "\n\n";
}

void student::schedule(char t, string c)
{
	if(t == 'M' or 'm')  {
		scheduled_courses[0] = c;
	}
	else if(t == 'A' or 'a') {
		scheduled_courses[1] = c;
	}
}



void students_ini(vector<student> &students, int student_count)
{
	for(int i = 1; i <= student_count; i++)
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