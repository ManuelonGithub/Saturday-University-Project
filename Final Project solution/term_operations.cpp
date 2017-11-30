//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"
#include <ctime>


void time_table_print(vector<course> &courses, int t, ostream &out)       // WIP: Creates a text file for every term processed, and prints out the time table for that semester
{
    out << "Term " << (t+1) << " Time-Table: " << "\n\n";

    if(courses.size() <= 0) {
        out << "N/A" << "\n";
    }

    else {
        for (int i = 0; i < courses.size(); i++) {
            if(courses[i].is_scheduled()) {
                out << "Course ID: " << courses[i].get_ID() << " - Room: " << courses[i].get_room() << " - Course time: ";
                if(courses[i].get_time() == 'm') {
                    out << "Morning  ";
                }
                else if(courses[i].get_time() == 'a') {
                    out << "Afternoon";
                }
                out << " - Students attending: " << courses[i].get_students() << "\n";
            }
        }
    }

    out << "\n";
}

bool Scheduler(vector<string> &FUS, vector<course> &total, bool time_slot_toggle, vector<student> &students)
{
    int count[total.size()];
    char time;
    int noCount=0;
    for (int i=0; i < total.size(); i++){ //initialize count
        count[i]=0;
    }

    for(int i=0;i<FUS.size();i++){
        if (FUS[i]=="No") {
            noCount++;
        }
        for(int j=0;j < total.size();j++){
            if(FUS[i]==total[j].get_ID()){
                count[j]++; // course gets a count
            }
        }
    }
    int max=0;
    int chosen=0;
    for(int i=0;i<total.size();i++){
        if(count[i]>max){
            max=count[i];
            chosen=i;
        }
    }
    if (noCount != FUS.size()) { // if at least one course was chosen by a student

        if(time_slot_toggle)    { time = 'm'; }
        else                    { time = 'a'; }
        total[chosen].schedule(time);

        for (int i=0; i < students.size(); i++) {
            if (total[chosen].get_ID() == FUS[i]) {
                students[i].schedule(time) ; // give the student the course at the specified time
            }
        }

        return false;
    }
    else {
        return true;
    }
}

void print_attendance(vector<string> &FUS, vector<course> &total, vector<student> &students, vector <classroom> &classrooms)
{
    cout << "Student       Courses taken" <<endl;
    for (int i=0; i < students.size(); i++){
        cout << "B" << students[i].get_id() << "               " << students[i].attendance() << endl;
    }
}

void term_completed(vector<student> &grad_st, vector<student> &st, vector<course> &c, vector<string> &sel_cs, reg_system &sys)      // WIP: Funcion to be called at the end of each semester
{
    for(int i = 0; i < st.size(); i++) {
        st[i].complete_courses();
        st[i].graduate(sys.core_courses());
    }
    for(int i = 0; i < c.size(); i++) {
        if(c[i].is_scheduled()) {
            c[i].clear_sch();
        }
    }
    fill(sel_cs.begin(), sel_cs.end(), "");
}

string course_selection(vector<course> &available, student &s, bool timing)
{
    bool is_option = true;
    vector<course> option;// new array of possibilities (never taken, has pre reqs, not scheduled already)
    
    if(!s.graduated()) {
        if((s.needs_mor_course() && timing) || (s.needs_aft_course() && !timing)) {
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
                //Pick a random integer between 0 and number of option courses
                int ran;
                ran = rand() % option.size();
                string bestChoice;
                bestChoice = option[ran].get_ID();
                //past.push_back(bestChoice);//Storing the student's wish for each iteration
                
                //cout<< "The FUS has selected course " << bestChoice << " for the student B" << s.get_id() << endl;
                
                s.set_selected_course(bestChoice);
                return bestChoice;
            }
        }
    }
    return "No";
}

int building_manager(vector<course> &total, vector<student> &students, vector <classroom> &classrooms, int term, ostream &timetable)
{
    int count[total.size()];
    int countaft[total.size()];
    int c[total.size()];
    int caft[total.size()];
    for (int i=0; i < total.size(); i++){ //initialize count
        count[i]=0;
        countaft[i]=0;
        c[i]=0;
        caft[i]=0;
    }
    for(int i=0;i<students.size();i++){
        for(int j=0;j<total.size();j++){
            if(students[i].mor_course()==total[j].get_ID()){
                count[j]++;
            }
            if(students[i].aft_course()==total[j].get_ID()){
                countaft[j]++;
            }

        }
    }
    string w[total.size()];
    for(int i=0;i<total.size();i++){
        w[i]=total[i].get_ID();
    }
    for(int i=0;i<total.size();i++){//this part of the code cancels classes with less than 3 students
        if (count[i]<3){
            count[i]=0;
        }
        if (countaft[i]<3){
            countaft[i]=0;
        }
    }
    string tempst;
    int temp=0;
    for(int i=1;i<total.size();i++){
        bool flag= 0;
        for(int j=0;j<total.size()-1;j++){
            if(count[j]<count[j+1]){
                temp=count[j];
                count[j]=count[j+1];
                count[j+1]=temp;
                tempst=w[j];
                w[j]=w[j+1];
                w[j+1]=tempst;
                flag=1;
            }
        }
        if (!flag){ break;}
    }
    int k=0;
    for(int i=0;i<total.size();i++){
        if(count[i]!=0){
            c[k]=count[i];
            k++;
        }
    }
    vector<course>z;
    course tempo(" ");
    for(int i=0;i<total.size();i++){
        if(count[i]!=0){
            tempo.set_ID(w[i]);
            tempo.schedule('m');
            z.push_back(tempo);
            
        }
    }
    /**************************************************************************************/
    
    string waft[total.size()];
    for(int i=0;i<total.size();i++){
        waft[i]=total[i].get_ID();
    }
    string tempstaft;
    int tempaft=0;
    for(int i=1;i<total.size();i++){
        bool flag= 0;
        for(int j=0;j<total.size()-1;j++){
            if(countaft[j]<countaft[j+1]){
                tempaft=countaft[j];
                countaft[j]=countaft[j+1];
                countaft[j+1]=tempaft;
                tempstaft=waft[j];
                waft[j]=waft[j+1];
                waft[j+1]=tempstaft;
                flag=1;
            }
        }
        if (!flag){ break;}
    }
    int k1=0;
    for(int i=0;i<total.size();i++){
        if(countaft[i]!=0){
            caft[k1]=countaft[i];
            k1++;
        }
    }

    vector<course>zaft;
    course tempoaft(" ");

    for(int i=0;i<total.size();i++){
        if(countaft[i]!=0){
            tempoaft.set_ID(waft[i]);
            tempoaft.schedule('a');
            zaft.push_back(tempoaft);
        }
    }

    int room=0,room1=0;//change to zero

    for(int i=0;i<k;i++){
        z[i].set_room(classrooms[room].get_room());
        room++;
    }

    for(int i=0;i<k1;i++){
        zaft[i].set_room(classrooms[room1].get_room());
        room1++;
    }

    for(int i=0;i<z.size();i++){ //check classes selected for the morning
        for(int j=0;j<classrooms.size();j++){ // check classes each room
            if(z[i].get_room()==classrooms[j].get_room()){ //if the morning classroom is equal to
                int studentvector=students.size();
                while(c[i]>classrooms[j].get_maxcap()){
                    if(students[studentvector].mor_course()==z[i].get_ID()){
                        c[i]--;
                        students[studentvector].clear_m_class();
                    }
                    studentvector--;
                }
            }
        }
    }

    for(int i=0;i<zaft.size();i++){ //check classes selected for the morning
        for(int j=0;j<classrooms.size();j++){ // check classes each room
            if(zaft[i].get_room()==classrooms[j].get_room()){ //if the morning classroom is equal to
                int studentvectoraft=students.size();
                while(caft[i]>classrooms[j].get_maxcap()){
                    if(students[studentvectoraft].aft_course()==zaft[i].get_ID()){
                        caft[i]--;
                        students[studentvectoraft].clear_a_class();
                    }
                    studentvectoraft--;
                }
            }
        }
    }


    for(int i = 0; i < zaft.size(); i++) {
        zaft[i].set_students(caft[i]);
    }


    for(int i=0;i<zaft.size();i++){
        z.push_back(zaft[i]);
    }

    for(int i = 0; i < k; i++) {
        z[i].set_students(c[i]);
    }

    time_table_print(z, term, timetable);
    z.clear();
    zaft.clear();
    int sum =0;
    for(int i=0;i<k;i++){
        sum=sum+c[i]+caft[i];
    }
    return sum;
}

