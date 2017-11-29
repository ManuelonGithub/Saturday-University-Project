//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"
#include <ctime>


void time_table_print(vector<course> &courses, int t)       // WIP: Creates a text file for every term processed, and prints out the time table for that semester
{
    string term = "Term " + to_string((t+1)) + " Time Table.txt";
    ofstream fileout;
    fileout.open(term.c_str());

    fileout << term << "\n\n";

    for (int i = 0; i < courses.size(); i++) {
        if(courses[i].is_scheduled()) {
            fileout << "Course ID: " << courses[i].get_ID() << " - Room: " << courses[i].get_room() << " - Course time: ";
            if(courses[i].get_time() == 'm') {
                fileout << "Morning";
            }
            else if(courses[i].get_time() == 'a') {
                fileout << "Afternoon";
            }
            fileout << "\n\n";
        }
    }

    fileout.close();
}

void time_table_creation_test_1(vector<course> &courses, vector<classroom> &classrooms)     // A test to create a time table
{
    for (int i = 0; i < classrooms.size(); i++)
    {
        if((i % 2) == 0) {
            courses[i].schedule('m');
        }
        else {
            courses[i].schedule('a');
        }
        courses[i].set_room(classrooms[i].get_room());
    }
}

int calculateTuition(vector<course> &term) {
    int tuition=0; // new term, reset tuition
    vector<int> tuitionHistory; // This will hold the tuition paid at each term
    for (int i=0; i < term.size(); i++){
        if(term[i].is_scheduled())
            tuition++;
    }
    tuitionHistory.push_back(tuition);
    return tuition; // Is this value 0, 1, or 2 always?
}

void Scheduler(vector<string> &FUS, vector<course> &total, bool time_slot_toggle, vector<student> &students, vector<scheduled_course> &sched_courses){
    // room is the iteration count. even == morning odd == afternoon
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
    //cout << FUS.size() << endl;
    for (int j=0; j < total.size(); j++){ // finds course with most wishes
        cout<< total[j].get_ID() <<" has " << count[j]<<endl;
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
        sched_courses.emplace_back(scheduled_course(total[chosen].get_ID(), time, max));

        for (int i=0; i < students.size(); i++) {
            if (total[chosen].get_ID() == FUS[i]) {
                cout << "Student B" << students[i].get_id()<<" will take course " << total[chosen].get_ID() << " in the " << time << endl;
                students[i].schedule(time) ; // give the student the course at the specified time
            }
        }
    }
    else {
        cout << "Nothing assigned this time" << endl;
    }
}

void print_attendance(vector<string> &FUS, vector<course> &total, vector<student> &students, vector <classroom> &classrooms) {
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
                //cout << ran;
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

int building_manager(vector<course> &total, vector<student> &students, vector <classroom> &classrooms, int term){
    int count[total.size()];
    int countaft[total.size()];
    for (int i=0; i < total.size(); i++){ //initialize count
        count[i]=0;
        countaft[i]=0;
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
            if(count[j]>count[j+1]){
                temp=count[j];
                count[j]=count[j+1];
                count[j+1]=temp;
                tempst=w[j];
                w[j]=w[j+1];
                w[j+1]=tempst;
                flag=1;
            }
        }
        if (flag==false){ break;}
    }
    int k=0;
    int c[total.size()];
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
    for(int i=0;i<z.size();i++){
        cout<<z[i].get_room()<<" ";
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
            if(countaft[j]>countaft[j+1]){
                tempaft=countaft[j];
                countaft[j]=countaft[j+1];
                countaft[j+1]=tempaft;
                tempstaft=waft[j];
                waft[j]=waft[j+1];
                waft[j+1]=tempstaft;
                flag=1;
            }
        }
        if (flag==false){ break;}
    }
    for(int i=0;i<total.size();i++){
        if(countaft[i]!=0){
            c[k]=countaft[i];
            k++;
        }
    }
    course tempoaft(" ");
    for(int i=0;i<total.size();i++){
        if(countaft[i]!=0){
            tempoaft.set_ID(waft[i]);
            tempoaft.schedule('a');
            z.push_back(tempoaft);

        }
    }
    int room=classrooms.size(), room1=classrooms.size();
    for(int i=0;i<k;i++){
        if(z[i].get_time()=='m'){
            do{
                room--;
            }while(c[i]>=classrooms[room].get_maxcap()-1);
            z[i].set_room(classrooms[room].get_room());
        }
        else{
            do{
                room1--;
            }while(c[i]>=classrooms[room1].get_maxcap()-1);
            z[i].set_room(classrooms[room].get_room());
        }
    }
    int sum =0;
    time_table_print(z, term);
    for(int i=0;i<k;i++){
        sum=sum+c[i];
    }
    return sum;
}