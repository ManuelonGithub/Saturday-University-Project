#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstlib>

using namespace std;

class course{
	private: 
			string courseID;
			vector<string> pre_req;
	
	public:
			course(string cID = " ")	{ courseID = cID; }
			void set_pre_req{string ID}	{ pre_req.pushback(id); }
};

class classroom{
	private:
			string room;
			int vacancy;
			
	public:
			classroom(string r = " ", int vac = 0)	{ room = r;	vacancy = vac; }
};

class student{
	private:
			int st_ID;
			vector<string> completed_courses;
			int terms_completed;
			bool graduated;
	
	public:
			student(int s_ID = 0, int t_c = 0, bool g = false)	{ st_ID = s_ID;	terms_completed = t_c;	graduated = g; }
};

void system_parameters_read(string Filepath, int &st_n, int &t_T, int &t_r_c, int &s_T, int &s_st);

int main()
{
	vector<course> courses;
	vector<classroom> classrooms;
	list<student> students;
	
	int st_num;				// Total number of students going into the University
	int total_T;			// Total amount of terms we're going to process
	int total_req_crs;		// Core courses + 2 electives
	int sample_T;
	int sample_st;
	int total_courses_given;
	
	bool ini_status = true;
	
	ifstream courses_in("courses.txt");
	ifstream classrooms_in("classrooms.txt");
	
	system_parameters_read("system-parameters-in.txt", st_num, total_T, total_req_crs, sample_T, sample_st);

	courses_read("courses.txt",courses, total_courses_given);
	
	classrooms_read(classrooms);
	
	students_ini(students);
	
	return 0;
}

bool system_parameters_read(string Filepath, int &st_n, int &t_T, int &t_r_c, int &s_T, int &s_st)
{
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

void courses_read(string Filepath, vector<course> &courses, int &total_courses_given)
{
	course *c;
	string str;
	
	courses_in.open(Filepath.c_str());
	
	if(!courses_in)
	{
		cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
		
		exit(0);
	}
	else
	{
		courses_in >> total_courses_given;
		
		while(getline(courses_in, str))
		{
			istringstream ss(str);
			string id;
			
			ss >> id;
			c->new course(id); 
			
			while(ss >> id)
			{
				c->set_pre_req(id);
			}
			
			courses.pushback(c);
		}
		
}
