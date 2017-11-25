#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class scheduledcourses{
private:
    int count;
    int count1;
    int count2;
    vector<int> nummon;//number of students scheduled to a specific course in the morning
    vector<int> numaft;//number of students scheduled to a specific course in the afternoon
    vector<string> morning;//courses that made it past the scheduling process and are about to be put in time slots in the morning
    vector<string> afternoon;//courses that made it past the scheduling process and are about to be put in time slots in the afternoon
public:
    scheduledcourses(int sz);
    void push(int cap,string course);
    void write(ostream& out) const;
};
int main(void) {
    int n;//number of students
    int x;//x is the amount of courses there are
    int count[x];//counter for how many students are taking each course.
    int rooms;//number or rooms available
    int tsc=rooms*2;//this is the amount of time slots that we have
    vector<string> v(n,"coursecode");//vector with each studentd selected courses. when in code take this out
    vector<string> u(x,"coursecode");//vector u is the list of all the courses. when in code take this out
    vector<string> w(tsc,"-");//vector x for all the scheduled courses
    int timeslotsize[tsc];//amount of students in each course scheduled courses
    
    //for loop for schedule iteration starts here. infact, student count sould be the last for loop and just counts
    //up to the amount of iterations we are supposed to have
    
    /************************************************************/ //this schedules the class with the maximum amount of students that want to take it
    for(int h=0;h<=tsc; h++){   //this just increases so that the scheduled classes and the amount of students taking it
                                //can be stored in a vector and an array respectively
        for(int i=0;i<v.size();i++){
            for(int j=0;j<x;j++){
                if(v[i]==u[j]){
                    count[j]++;
                }
            }
        }
        int max=0;
        string scheduled;
        for(int i=0;i<x;i++){
            if(count[i]>max){
                max=count[i];
                scheduled=u[i];
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=scheduled){
                v[i]=" ";
            }
        }
        w[h]=scheduled;
        timeslotsize[h]=max;
    }
    /***************************************************************/
    //for loop for schedule iteration should end here
    
    
    //this step should be after all iterations have been completed. This means this whole thing has to be in a for loop :) pretty please
    scheduledcourses mysched(rooms);//this part of the code puts the courses into the schedule randomly
    for(int i=0;i<tsc;i++){
        mysched.push(timeslotsize[i],w[i]);
    }
    mysched.write(cout);
    
    scheduledcourses myschedref(rooms);

    int value,hole;//this part of the code arranges the courses according to the amount of students taking it
    string value1;
    for(int i=1;i<tsc;i++){
        value=timeslotsize[i];
        value1=w[i];
        hole=i;
        while(hole>0&& timeslotsize[hole-i]>value){
            timeslotsize[hole]=timeslotsize[hole-1];
            w[hole]=w[hole-1];
        }
        timeslotsize[hole]=value;
        w[hole]=value1;
    }
    
    for(int i=0;i<tsc;i++){//this part of the code cancels classes with less than 3 students
        if (timeslotsize[i]<3){
            w[i]=" ";
            timeslotsize[i]=0;
        }
    }
    for(int i=0;i<tsc;i++){
        myschedref.push(timeslotsize[i],w[i]);
    }
    myschedref.write(cout);
    return 0;
}
scheduledcourses::scheduledcourses(int sz):nummon(sz),numaft(sz),morning(sz),afternoon(sz){
    count=0;
    count1=0;
    count2=0;
}
void scheduledcourses::push(int cap,string course){
    if(count%2==0){
        nummon[count]=cap;
        morning[count1]=course;
        count1++;
    }
    else{
        numaft[count]=cap;
        afternoon[count2]=course;
        count2++;
    }
    count++;
}
void scheduledcourses::write(ostream& out) const{
    out<<"Mornings"<<endl;
    for(int i=0; i < count1; i++){
        out << morning[i] << "|"<<nummon[i];
    }
    out << endl;
    out<<endl<<"Afternoons"<<endl;
    for(int i=0; i < count2; i++){
        out << afternoon[i] << "|"<<numaft[i];
    }
    out << endl;
}
