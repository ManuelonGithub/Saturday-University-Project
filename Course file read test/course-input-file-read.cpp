#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class course
{
private:
	string courseID;
	vector<string> pre_req;

public:
	explicit course(string cID = " ")	{ courseID = cID; }
	void set_pre_req(string const id )	{ pre_req.push_back(id); }
	void write(ostream &out) const;
};

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

int main()
{
	vector<course> courses;

	int total_courses_given;

	courses_read("courses.txt",courses, total_courses_given);

	cout << total_courses_given << endl;

	for(int i = 0; i <= total_courses_given; i++)
	{
		courses[i].write(cout);
	}

	return 0;
}

void course::write(ostream &out) const
{
	out << courseID << ": " << endl;
	for (const auto &i : pre_req) {
		out << "\t" << i << endl;
	}
}
