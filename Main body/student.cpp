//
// Created by Manuel on 22/11/2017.
//
#include <iostream>
#include "student.h"

using namespace std;


student::student(int s_ID, int t_c, bool g)
{
    st_ID = s_ID;
    terms_completed = t_c;
    graduated = g;
}