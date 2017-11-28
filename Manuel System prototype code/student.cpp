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
void student::set_selected_course(string c) { selected_course = c; }        // Method that retrieves the student's ID
int student::get_id()                       { return st_ID; }               // Method that retrieves the student's ID
bool student::graduated()                   { return grad;}                 // Method that checks if the student has graduated (true) or not (false)
string student::attendance(int i)           { return scheduled_courses[i];}

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
		for(int i = 0; i < terms_completed; i++)
		{
			out << completed_courses[i];
		}
	}
	out << "\n\n";
}


void student::schedule(char t, string c)
{
	if((t == 'm') && (scheduled_courses[0]== "")) { // don't over write
		scheduled_courses[0] = c;
	}
	if((t == 'a') && (scheduled_courses[1]== "")){
		scheduled_courses[1] = c;
	}
	//completed_courses.push_back(c); // complete record of courses done by the student. Need this gone, have a funciton that deals with this
}

/*
void student::schedule(char t)      // Method that schedules the selected courses of the student to the morning of afternoon class slot for the student
{
	if(t == 'M' or 'm')  {
		m_class = selected_course;
	}
	else if(t == 'A' or 'a') {
		a_class = selected_course;
	}
}
*/

string student :: bestChoice(vector<course> &available){ //take courses from main as argument

	int preReqDone;
	string noChoice = "No";
	vector<string> past; // the courses the student has gotten on each iteration of the FUS
	vector<course> option;// new array of possibilities (never taken, has pre reqs, not scheduled already)

	if ((scheduled_courses[0] == "") || (scheduled_courses[1] == "")){ // if student still needs at least one course this term
		for (int i=0; i < available.size(); i++) // Check all courses
		{
			preReqDone=0;
			for (int k=0; k < completed_courses.size(); k++) // on the next run this is actually runs
			{

				if ((available[i].get_ID() != completed_courses[k])) // if the student has course already, not an option
				{
					for (int h=0; h < available[i].getSizePreReq(); h++)
					{
						if (available[i].get_pre_req(h) == completed_courses[k])
						{
							preReqDone++; // number of prerequisites filled is increased
						}
					}
				}
			}
			if ((preReqDone >= available[i].getSizePreReq()) && (available[i].is_scheduled()==false))
			{
				option.push_back(available[i]);
			}
		}

		if (option.size() > 0 ) {
			//Pick a random integer between 0 and number of option courses
			int ran;
			ran = rand() % option.size();
			cout << ran;
			string bestChoice;
			bestChoice = option[ran].get_ID();
			past.push_back(bestChoice);//Storing the student's wish for each iteration

			//cout<< "The FUS has selected course " << bestChoice << " for the student B" << st_ID << endl;
			return bestChoice;
		}

	}

	return noChoice;

}

void student::complete_courses()    // Method that transfers the student's scheduled courses for that semester to the completed courses vector
{
	if(m_class != "") {
		completed_courses.push_back(m_class);
	}
	if(a_class != "") {
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
	m_class = a_class = selected_course = "";

	terms_completed++;
}

void student::graduate(int core)    // Method that determines if the student graduates or not
{
	if( core_courses_completed >= core && elective_courses_completed >= 2) {
		grad = true;
	}
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