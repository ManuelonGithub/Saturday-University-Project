#include "course.h"
#include "classroom.h"
#include "student.h"
#include "reg_system.h"
#include "term_operations.h"
void get_num_pre(vector <course> &courses);

int main()
{
    srand(time(NULL));
    reg_system sys{};                       // Our system parameters, in the form of a system object. See reg_system.h and reg_system.cpp for more information
    vector<course> courses;                 // A vector of all courses offered by the university. See course.h and course.cpp for more information
    vector<classroom> classrooms;           // A vector of all classrooms available to the courses. See classroom.h and classroom.cpp for more information
    vector<student> students;               // A vector of all students attending the university. See student.h and student.cpp for more information
    vector<scheduled_course> sched_courses;

    
    sys.create("system-parameters-in.txt");         // Takes in the system parameter input file and stores the pertinent information for the system. See reg_system.h and reg_system.cpp for more information
    courses_read("courses.txt", courses);           // Function that reads through the course input file creates courses with their pertinent information, and stores them in the university course vector
    classrooms_read("classrooms.txt", classrooms);  // Takes in the classroom input file and adds the classrooms available to the classrooms vector. See classroom.h and classroom.cpp for more information
    students_ini(students, sys.students());         // Initializes the vector of students attending the university. See student.h and student.cpp for more information

    get_num_pre(courses);

    for (int i=0; i < students.size(); i++) {
        course_selection(courses, students[i]);
        cout << "Student B" << students[i].get_id() << " courses are: " << students[i].attendance() << "\n";
    }

    course_scheduling();

    //for(int i = 0; i < sys.terms_to_process(); i++){

    // while( !reg_n_sched_complete):

    // Course Selection  - done^TM

    // Sample student course selection print - not done

    // Course Scheduling - done^TM

    // Building manager duties - done^TM

    // Term time table print - DONE

    // tuition processing - not done (callum)

    //  tution = calculateTuition(courses);

    // courses taking by student during the term (must be sorted according to the number of taken courses in the semester) - not done

    // term_completed() - not done

    // Graduated student by this term - not done
    //}

    return 0;
}

void get_num_pre(vector <course> &courses){
    for (int i=0; i < courses.size(); i++) {
        for (int k=0; k < courses.size(); k++){
            if (courses[k].getSizePreReq() != 0) {
                for (int j=0; j < courses[k].getSizePreReq(); j++ ){
                    if (courses[i].get_ID() == courses[k].get_pre_req(j)){
                        courses[i].inc_k_value();
                    }
                }
            }
        }
    }
}
