//
// Created by manuel on 24/11/17.
//

#include <fstream>
#include <iomanip>
#include "term_operations.h"

void time_table_print(vector<course> &courses, int t)       // WIP: Creates a text file for every term processed, and prints out the time table for that semester
{
    string term = "Term " + to_string((t+1)) + " Time Table.txt";
    ofstream fileout;
    fileout.open(term.c_str());

    fileout << term << "\n\n";

    for (int i = 0; i < courses.size(); i++) {
        if(courses[i].is_scheduled()) {
            fileout << "Course ID: " << courses[i].get_ID() << " - Room: " << courses[i].get_room() << " - Course time: ";
            if(courses[i].course_time() == 'm') {
                fileout << "Morning";
            }
            else if(courses[i].course_time() == 'a') {
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
            courses[i].scheduling('m');
        }
        else {
            courses[i].scheduling('a');
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

void Scheduler(vector<string> &FUS, vector<course> &total,int timing, vector<student> &students, vector<classroom> &classrooms, int room){
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
                count[j]= count[j] + 1; // course gets a count
            }
        }
    }
    cout << FUS.size() << endl;
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
        if (timing==1) {// toggle between morning and afternoon
            time = 'm';
            classrooms[room].setCourseMorning(total[chosen].get_ID(),max);
        }
        else {
            time = 'a';
            classrooms[room].setCourseAfternoon(total[chosen].get_ID(),max);
        }

        total[chosen].scheduling(time); // it happens, course put on schedule. but where?

        for (int i=0; i < students.size(); i++){
            if (total[chosen].get_ID() == FUS[i]){
                cout << "Student B" << students[i].get_id()<<" will take course " << total[chosen].get_ID() << "in the " << time << endl;
                students[i].schedule(time, total[chosen].get_ID()) ; // give the student the course at the specified time
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
        cout << "B" << students[i].get_id() << "               " << students[i].attendance(0) << ","<< students[i].attendance(1)<<endl;
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

int building_manager(vector<course> &total, vector<student> &students, vector <classroom> &classrooms, int term){
    int count[total.size()];
    int countaft[total.size()];
    for (int i=0; i < total.size(); i++){ //initialize count
        count[i]=0;
        countaft[i]=0;
    }
    for(int i=0;i<students.size();i++){
        for(int j=0;j<total.size();j++){
            if(students[i].attendance(0)==total[j].get_ID()){
                count[j]++;
            }
            if(students[i].attendance(1)==total[j].get_ID()){
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
            tempo.scheduling('m');
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
            tempoaft.scheduling('a');
            z.push_back(tempoaft);
            
        }
    }
    int room=classrooms.size(),room1=classrooms.size();
    for(int i=0;i<k;i++){
        if(z[i].course_time()=='m'){
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

