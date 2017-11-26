//
// Created by Manuel on 22/11/2017.
//

#include <iostream>
#include <iomanip>
#include "classroom.h"
using namespace std;

classroom::classroom(int r, int vac)
{
    string name = "R" + to_string(r);
    room = name;
    vacancy = vac;
}

void classroom::write(ostream &out) const
{
    out << "Room '" << room << "' -> " << "vacancy of " << vacancy << "\n";
}