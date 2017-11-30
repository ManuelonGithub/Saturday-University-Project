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

void student::set_selected_course(string c) { selected_course = c; }        // Method that retrieves the student's ID
int student::get_id()                       { return st_ID; }               // Method that retrieves the student's ID
bool student::graduated()                   { return grad;}                 // Method that checks if the student has graduated (true) or not (false)
string student::attendance()           		{ return (m_class + "," + a_class);}
void student::clear_m_class()               {m_class = " ";}
void student::clear_a_class()               {a_class = " ";}

void student::write(ostream &out) const     // Method that prints pertinent student information to out
{
	out << "Student " << "B" << st_ID << ": " << "\n";
	out << setw(23) << "Graduated? ";
	if(grad) {
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
		for(int i = 0; i < completed_courses.size(); i++)
		{
			out << completed_courses[i] << ", ";
		}
	}
	out << "\n\n";
}

void student::schedule(char t)      // Method that schedules the selected courses of the student to the morning of afternoon class slot for the student
{
	if(t == 'm' && m_class.empty())  {
		m_class = selected_course;
	}
	else if(t == 'a' && a_class.empty()) {
		a_class = selected_course;
	}
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
	if(!m_class.empty() || !a_class.empty()) { terms_completed++; }
	m_class = a_class = selected_course = "";
}

void student::graduate(int core)    // Method that determines if the student graduates or not
{
	if( core_courses_completed >= core && elective_courses_completed >= 2) {
		grad = true;
	}
}

bool student::needs_mor_course()
{
	return m_class.empty();
}

bool student::needs_aft_course()
{
	return a_class.empty();
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

string student::aft_course() { return a_class; }
string student::mor_course() { return m_class; }

void student::graduated_write(ostream &out, int term) const
{
	if(terms_completed == (term+1)) {
		out << "Student B" << st_ID << " - " << " Courses completed: ";
		for(int i = 0; i < completed_courses.size(); i++) {
			out << completed_courses[i] << ", ";
		}
		out << "\n";
	}
}

void student::cancel_course(string c)
{
	if(m_class == c) {
		m_class = "";
	}
	if(a_class == c) {
		a_class = "";
	}
}

int student::courses_scheduled()
{
	int x = 0;
	if(!m_class.empty()) {x++;}
	if(!a_class.empty()) {x++;}
	return x;
}

void students_ini(vector<student> &students, int student_count)     // Function that initializes the vector of students attending the university
{
	for(int i = 1; i <= student_count; i++)
	{
		students.emplace_back(i);
	}
}

void print_all_students(ostream &out, vector<student> &students)    // Function that prints out all students and their pertinent information to out
{
	for(int i=0; i < students.size(); i++)
	{
		students[i].write(out);
	}
}
