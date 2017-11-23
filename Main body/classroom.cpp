//
// Created by Manuel on 22/11/2017.
//

#include <iostream>
#include <fstream>
#include <string>
#include "classroom.h"

using namespace std;

classroom::classroom(string r, int vac) { room = r;	vacancy = vac; }

void classroom::write(ostream &out) const
{
    out << "Room '" << room << "' :\n" << "\t" << "vacancy of " << vacancy << "\n";
}