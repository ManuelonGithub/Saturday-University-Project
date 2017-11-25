//
// Created by Manuel on 22/11/2017.
//

#include <iostream>
#include <vector>
#include "course.h"

using namespace std;

course::course(string cID, bool scheduled) { courseID = cID; }

void course::set_pre_req(string const id) { pre_req.push_back(id);}

void course::write(ostream &out) const
{
    out << courseID << ": " << "\n";
    if(!pre_req.empty()) {
        out << "\tpre-requisite courses: ";
        for (const auto &i : pre_req) {
            out << i << ", ";
        }
        out << "\n";
    }
    else  {
        out << "\tNo pre-requisite courses \n";
    }

}

void course::scheduling(char t)
{
    if (t == 'M' or 'A' or 'm' or 'a') {
        time = t;
        Scheduled = true;
    }
}

void course::clear_sch()
{
    Scheduled = false;
    time = ' ';
}

string course::ID_getter(void) 
{
	return courseID;
}

string course::getPreReq(int k)
{
	return pre_req[k];
}

int course::getSizePreReq(void)
{
	return pre_req.size();	
}
