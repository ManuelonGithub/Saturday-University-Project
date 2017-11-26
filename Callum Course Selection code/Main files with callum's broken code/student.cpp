//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include <iomanip>
#include "student.h"
#include "course.h"
#include <ctime>
#include <cstdlib>
using namespace std;

student::student(int s_ID, int t_c, bool g)
{
	st_ID = s_ID;
	terms_completed = t_c;
	graduated = g;
}

void student::term_completed() 				{ terms_completed++; }
void student::graduation() 					{ graduated = true; }
void student::set_selected_course(string c) { selected_course = c; }

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

string student :: bestChoice(vector<course> &available){ 
	int numCourses = available.size();  
	int preReqDone;
	vector<course> option;// the vector(array) of possible courses to be chosen at random. (no courses done already/missing prereqs)
	srand((unsigned)time(0)); //seed
	
	for (int i=0; i < numCourses; i++) 
	{
		preReqDone=0; 
		for (int k=0; k < numCourses; k++) 
		{	
			if (available[i].ID_getter() != completed_courses[k]) // if the student has course already, not an option
			{ 
				for (int h=0; h < available[i].getSizePreReq(); h++)
				{ 
					if (available[i].getPreReq(h) == completed_courses[k]) 
					{ 
						preReqDone++; // number of prerequisites filled is increased
					} 			
				}
			}
		} 	
		if (preReqDone >= available[i].getSizePreReq()) 
		{ 
		option.push_back(available[i]);
		}
	}

	//Pick a random integer between 0 and number of option courses
	int random_integer = int(option.size()*rand()/(RAND_MAX + 1.0)); 
	
	string bestChoice;	
	bestChoice = option[random_integer].ID_getter(); 
	
	return bestChoice;
}



