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

string student :: bestChoice(vector<course> &available){ //take courses from main as argument

    int preReqDone;
    string noChoice = "No course works for this sad, sorry student";
	vector<string> past; // the courses the student has gotten on each iteration of the FUS
	vector<course> option;// new array of possibilities (never taken, has pre reqs, not scheduled already)

	for (int i=0; i < available.size(); i++)
	{
		preReqDone=0;
		for (int k=0; k < completed_courses.size(); k++)
		{
			if ((available[i].get_ID() != completed_courses[k]) && (available[i].is_scheduled()==false)) // if the student has course already, not an option
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
        string bestChoice;
        bestChoice = option[ran].get_ID();
        past.push_back(bestChoice);//Storing the student's wish for each iteration

        //cout<< "The FUS has selected course " << bestChoice << " for the student B" << st_ID << endl;
        return bestChoice;
    }
    
    else
        return noChoice;

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
