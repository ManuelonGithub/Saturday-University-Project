//
// Created by Manuel on 22/11/2017.
//
#include <iomanip>
#include "student.h"
#include <ctime>


student::student(int s_ID, int t_c, bool g)     // Class student constructor
{
	st_ID = s_ID;
	terms_completed = t_c;
	grad = g;
	core_courses_completed = elective_courses_completed = 0;
}

void student::term_completed() 				{ terms_completed++; }          // Method that increments the amount of terms completed
int student::get_id()                       { return st_ID; }               // Method that retrieves the student's ID
bool student::graduated()                   { return grad;}                 // Method that checks if the student has graduated (true) or not (false)
string student::attendance()           		{ return (reg_courses[0] + "," + reg_courses[1]);}

void student::schedule(string a, string b)      // Method that schedules the selected courses of the student to the morning of afternoon class slot for the student
{
	reg_courses[0] = a;
	reg_courses[1] = b;
}

void student::complete_courses()    // Method that transfers the student's scheduled courses for that semester to the completed courses vector
{
	if(!m_class.empty()) {
		completed_courses.push_back(m_class);
	}
	if(!a_class.empty()) {
		completed_courses.push_back(a_class);
	}
	if(m_class[0] == 'c') {
		core_courses_completed++;
	}
	else if(m_class[0] == 'e') {
		elective_courses_completed++;
	}
	if(a_class[0] == 'c') {
		core_courses_completed++;
	}
	else if(a_class[0] == 'e') {
		elective_courses_completed++;
	}
	m_class = a_class = "";

	terms_completed++;
}

void student::graduate(int core)    // Method that determines if the student graduates or not
{
	if( core_courses_completed >= core && elective_courses_completed >= 2) {
		grad = true;
	}
}

bool student::completed_course(string course)
{
	for(int i = 0; i < completed_courses.size(); i++) {
		if(completed_courses[i] == course)
		{
			return true;
		}
	}
	return false;
}

bool student::needs_courses() {
	return reg_courses[0].empty() || reg_courses[1].empty();
}

void students_ini(vector<student> &students, int student_count)     // Function that initializes the vector of students attending the university
{
	for(int i = 1; i <= student_count; i++)
	{
		students.emplace_back(i);
	}
}
