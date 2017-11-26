//
// Created by Manny on 22/11/2017.
//

#include <iostream>
using namespace std;

#ifndef MAIN_BODY_CLASSROOM_H
#define MAIN_BODY_CLASSROOM_H

class classroom{
private:
    string room;
    int vacancy;

public:
    classroom(int r, int vac);
    void write(ostream &out) const;
};

#endif //MAIN_BODY_CLASSROOM_H
