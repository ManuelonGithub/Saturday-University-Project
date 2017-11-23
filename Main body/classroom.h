//
// Created by Manuel on 22/11/2017.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef MAIN_BODY_CLASSROOM_H
#define MAIN_BODY_CLASSROOM_H

class classroom{
private:
    string room;
    int vacancy;

public:
    classroom(string r = " ", int vac = 0);
    void write(ostream &out) const;
};

#endif //MAIN_BODY_CLASSROOM_H
