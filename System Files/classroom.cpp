//
// Created by Manuel on 22/11/2017.
//
#include <iomanip>
#include <fstream>
#include "classroom.h"

classroom::classroom(int r, int vac)        // Class classroom constructor
{
    string name = "R" + to_string(r);
    room_name = name;
    vacancy = vac;
}

string classroom::get_room() { return room_name; }      // Method that retrieves the designated room name

void classroom::write(ostream &out) const       // Method that prints the classroom's pertinent information to out
{
    out << "Room '" << room_name << "' -> " << "vacancy of " << vacancy << "\n";
}

void classrooms_read(string Filepath, vector<classroom> &classrooms)    // Function that takes in the classroom input file and adds the classrooms available to the classrooms vector
{
    ifstream rooms_in;
    int vac, r, rn;

    rooms_in.open(Filepath.c_str());

    if(!rooms_in)
    {
        cout << "error opening courses input file. Make sure the name of the file is: courses.txt" << endl;
        exit(1);
    }
    else
    {
        rooms_in >> r;

        for(int i = 0; i <= r; i++)
        {
            rn = i;
            rooms_in >> vac;
            classrooms.emplace_back(rn, vac);
        }
    }

    rooms_in.close();
}

void print_all_classrooms(ostream &out, vector<classroom> c)    // Function that prints out all classrooms and their pertinent information
{
    for(int i = 0; i < c.size(); i++)
    {
        c[i].write(out);
    }
    out << "\n";
}