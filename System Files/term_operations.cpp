//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"

void course_selection(vector<course> &available, student &s)
{
    bool is_option = true;
    vector<course> option;// new array of possibilities (never taken, has pre reqs, not scheduled already)
    
    if(!s.graduated()) {
        if((s.needs_courses())) {
            for(int i = 0; i < available.size(); i++) {
                if(!s.completed_course(available[i].get_ID()) && !available[i].is_scheduled()) {
                    for(int j = 0; j < available[i].getSizePreReq(); j++) {
                        if(!s.completed_course(available[i].get_pre_req(j))) {
                            is_option = false;
                            break;
                        }
                    }
                    if(is_option) {
                        option.push_back(available[i]);
                    }
                }
                is_option = true;
            }
            
            if (!option.empty()) {
                int m1 = 1, m2 = 0, tmp = 0;

                for(int i = 0; i < option.size(); i++) {
                    if(option[i].get_k_value() > option[m2].get_k_value()) {
                        m2 = i;
                    }
                    if(option[m2].get_k_value() > option[m1].get_k_value()) {
                        tmp = m2;
                        m2 = m1;
                        m1 = tmp;
                    }
                }
                s.schedule(option[m1].get_ID(), option[m2].get_ID());
            }
        }
    }
}


